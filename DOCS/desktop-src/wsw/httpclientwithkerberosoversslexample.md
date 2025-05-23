---
title: HttpClientWithKerberosOverSslExample
description: This example shows a HTTP client that sends request-reply messages, with kerberos over SSL mixed-mode security.
ms.assetid: 48b20c9b-38e7-472c-9606-b454850e14c1
keywords:
- HttpClientWithKerberosOverSslExample Native-Web-Services
- WWSAPI
- WWS
ms.topic: reference
ms.date: 05/31/2018
---

# HttpClientWithKerberosOverSslExample

This example shows a HTTP client that sends request-reply messages, with kerberos over SSL mixed-mode security. In this setup, the transport connection is protected (signed, encrypted) by SSL which also provides server authentication. Client authentication is provided by a kerberos APREQ ticket in a WS-Security header in the message.

-   [HttpClientWithKerberosOverSsl.cpp](#httpclientwithkerberosoversslcpp)
-   [PurchaseOrder.wsdl](#purchaseorderwsdl)
-   [Makefile](#makefile)

## HttpClientWithKerberosOverSsl.cpp


```C++
//------------------------------------------------------------
// Copyright (C) Microsoft.  All rights reserved.
//------------------------------------------------------------

#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include "WebServices.h"
#include "process.h"
#include "string.h"
$$RC_START_HIGHLIGHT
#include "wincrypt.h"
$$RC_END_HIGHLIGHT
#include "PurchaseOrder.wsdl.h"

// Print out rich error info
void PrintError(HRESULT errorCode, WS_ERROR* error)
{
    wprintf(L"Failure: errorCode=0x%lx\n", errorCode);

    if (errorCode == E_INVALIDARG || errorCode == WS_E_INVALID_OPERATION)
    {
        // Correct use of the APIs should never generate these errors
        wprintf(L"The error was due to an invalid use of an API.  This is likely due to a bug in the program.\n");
        DebugBreak();
    }

    HRESULT hr = NOERROR;
    if (error != NULL)
    {
        ULONG errorCount;
        hr = WsGetErrorProperty(error, WS_ERROR_PROPERTY_STRING_COUNT, &errorCount, sizeof(errorCount));
        if (FAILED(hr))
        {
            goto Exit;
        }
        for (ULONG i = 0; i < errorCount; i++)
        {
            WS_STRING string;
            hr = WsGetErrorString(error, i, &string);
            if (FAILED(hr))
            {
                goto Exit;
            }
            wprintf(L"%.*s\n", string.length, string.chars);
        }
    }
Exit:
    if (FAILED(hr))
    {
        wprintf(L"Could not get error string (errorCode=0x%lx)\n", hr);
    }
}

// Main entry point
int __cdecl wmain(int argc, __in_ecount(argc) wchar_t **argv)
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);
    
    HRESULT hr = NOERROR;
    WS_ERROR* error = NULL;
    WS_CHANNEL* channel = NULL;
    WS_MESSAGE* requestMessage = NULL;
    WS_MESSAGE* replyMessage = NULL;
    WS_HEAP* heap = NULL;
    
    // Command line parameter specifies the SPN for the target server.
    WS_STRING serviceSpn;
    if (argc == 2)
    {
        serviceSpn.chars = argv[1];
        size_t length = wcslen(
            serviceSpn.chars);
        // let's make sure the length is within a reasonable limit
        if (1024 >= length)
        {
            serviceSpn.length = (ULONG) length;
        }
        else
        {
            wprintf(
                L"SPN parameter is too long: '%s'\n",
                serviceSpn.chars);
            return 1;
        }
    }
    else
    {
        wprintf(
            L"Service SPN parameter is missing.\n");
        return 1;
    }
    
$$RC_START_HIGHLIGHT
    // declare and initialize a windows credential
    WS_DEFAULT_WINDOWS_INTEGRATED_AUTH_CREDENTIAL windowsCredential = {}; // zero out the struct
    windowsCredential.credential.credentialType = WS_DEFAULT_WINDOWS_INTEGRATED_AUTH_CREDENTIAL_TYPE; // set the credential type
    
    // declare and initialize a kerberos APREQ message security binding
    WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING kerberosBinding = {}; // zero out the struct
    kerberosBinding.binding.bindingType = WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING_TYPE; // set the binding type
    kerberosBinding.bindingUsage = WS_SUPPORTING_MESSAGE_SECURITY_USAGE; // set the binding usage
    kerberosBinding.clientCredential = &windowsCredential.credential;
    
    // declare and initialize an SSL transport security binding
    WS_SSL_TRANSPORT_SECURITY_BINDING sslBinding = {}; // zero out the struct
    sslBinding.binding.bindingType = WS_SSL_TRANSPORT_SECURITY_BINDING_TYPE; // set the binding type
    
    // declare and initialize the array of all security bindings
    WS_SECURITY_BINDING* securityBindings[2] = { &sslBinding.binding, &kerberosBinding.binding };
    
    // declare and initialize the security description
    WS_SECURITY_DESCRIPTION securityDescription = {}; // zero out the struct
    securityDescription.securityBindings = securityBindings;
    securityDescription.securityBindingCount = WsCountOf(securityBindings);
$$RC_END_HIGHLIGHT
    WS_ENDPOINT_ADDRESS address;
    WS_STRING serviceUrl = WS_STRING_VALUE(L"https://localhost:8443/example");
    WS_SPN_ENDPOINT_IDENTITY serviceIdentity;
    serviceIdentity.identity.identityType = WS_SPN_ENDPOINT_IDENTITY_TYPE;
    serviceIdentity.spn = serviceSpn;
    
    // Create an error object for storing rich error information
    hr = WsCreateError(
        NULL, 
        0, 
        &error);
    if (FAILED(hr))
    {
        goto Exit;
    }
    
    // Create a heap to store deserialized data
    hr = WsCreateHeap(
        /*maxSize*/ 2048, 
        /*trimSize*/ 512, 
        NULL, 
        0, 
        &heap, 
        error);
    if (FAILED(hr))
    {
        goto Exit;
    }
    
$$RC_START_HIGHLIGHT
    // Create a channel
    hr = WsCreateChannel(
        WS_CHANNEL_TYPE_REQUEST, 
        WS_HTTP_CHANNEL_BINDING, 
        NULL, 
        0, 
        &securityDescription, 
        &channel, 
        error);
    if (FAILED(hr))
    {
        goto Exit;
    }
$$RC_END_HIGHLIGHT
    
    hr = WsCreateMessageForChannel(
        channel,
        NULL, 
        0, 
        &requestMessage, 
        error);
    if (FAILED(hr))
    {
        goto Exit;
    }
    
    hr = WsCreateMessageForChannel(
        channel,
        NULL, 
        0, 
        &replyMessage, 
        error);
    if (FAILED(hr))
    {
        goto Exit;
    }
    
    
    // Initialize address of service
    address.url = serviceUrl;
    address.headers = NULL;
    address.extensions = NULL;
    address.identity = &serviceIdentity.identity;
    
    // Open channel to address
    hr = WsOpenChannel(channel, &address, NULL, error);
    if (FAILED(hr))
    {
        goto Exit;
    }
    
    // Send some request-replies
    for (int i = 0; i < 100; i++)
    {
        // Initialize purchase order
        _PurchaseOrderType purchaseOrder;
        purchaseOrder.quantity = 100;
        purchaseOrder.productName.chars = L"Pencil";
        purchaseOrder.productName.length = 6;
        
        _OrderConfirmationType orderConfirmation;
        
        // Send purchase order, get order confirmation
        hr = WsRequestReply(
            channel,
            requestMessage, 
            &PurchaseOrder_wsdl.messages.PurchaseOrder, 
            WS_WRITE_REQUIRED_VALUE,
            &purchaseOrder,
            sizeof(purchaseOrder),
            replyMessage, 
            &PurchaseOrder_wsdl.messages.OrderConfirmation, 
            WS_READ_REQUIRED_VALUE, 
            heap, 
            &orderConfirmation, 
            sizeof(orderConfirmation), 
            NULL, 
            error);
        
        if (FAILED(hr))
        {
            goto Exit;
        }
        
        // Print out confirmation contents
        wprintf(L"Expected ship date for order %lu is %.*s\n",
            orderConfirmation.orderID,
            orderConfirmation.expectedShipDate.length,
            orderConfirmation.expectedShipDate.chars);
        
        // Reset the message so it can be used again
        hr = WsResetMessage(requestMessage, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
        
        // Reset the message so it can be used again
        hr = WsResetMessage(replyMessage, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
        
        // Initialize request for order status
        _GetOrderStatusType getOrderStatus;
        getOrderStatus.orderID = orderConfirmation.orderID;
        
        _GetOrderStatusResponseType getOrderStatusResponse;
        
        // Send order status request, get order status reply
        hr = WsRequestReply(
            channel,
            requestMessage, 
            &PurchaseOrder_wsdl.messages.GetOrderStatus, 
            WS_WRITE_REQUIRED_VALUE,
            &getOrderStatus,
            sizeof(getOrderStatus),
            replyMessage, 
            &PurchaseOrder_wsdl.messages.GetOrderStatusResponse, 
            WS_READ_REQUIRED_VALUE, 
            heap, 
            &getOrderStatusResponse, 
            sizeof(getOrderStatusResponse), 
            NULL, 
            error);
        
        if (FAILED(hr))
        {
            goto Exit;
        }
        
        // Print out order status
        wprintf(L"Order status for order %lu is: %.*s\n",
            getOrderStatusResponse.orderID,
            getOrderStatusResponse.status.length,
            getOrderStatusResponse.status.chars);
        
        // Reset the message so it can be used again
        hr = WsResetMessage(requestMessage, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
        
        // Reset the message so it can be used again
        hr = WsResetMessage(replyMessage, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
        
        // Make same request, but this time with an invalid order ID
        getOrderStatus.orderID = 321;
        hr = WsRequestReply(
            channel,
            requestMessage, 
            &PurchaseOrder_wsdl.messages.GetOrderStatus, 
            WS_WRITE_REQUIRED_VALUE,
            &getOrderStatus,
            sizeof(getOrderStatus),
            replyMessage, 
            &PurchaseOrder_wsdl.messages.GetOrderStatusResponse, 
            WS_READ_REQUIRED_VALUE, 
            heap, 
            &getOrderStatusResponse, 
            sizeof(getOrderStatusResponse), 
            NULL, 
            error);
        
        // Check to see if we got a fault
        if (hr == WS_E_ENDPOINT_FAULT_RECEIVED)
        {
            // Print the strings in the error object
            PrintError(hr, error);
        
            // TODO: the following should be removed when wsutil generates it
            WS_XML_STRING _faultDetailName = WS_XML_STRING_VALUE("OrderNotFound");
            WS_XML_STRING _faultDetailNs = WS_XML_STRING_VALUE("https://example.com");
            WS_XML_STRING _faultAction = WS_XML_STRING_VALUE("https://example.com/fault");
            WS_ELEMENT_DESCRIPTION _faultElementDescription = { &_faultDetailName, &_faultDetailNs, WS_UINT32_TYPE, NULL };
            WS_FAULT_DETAIL_DESCRIPTION orderNotFoundFaultTypeDescription = { &_faultAction, &_faultElementDescription };
        
            // Try to get the fault detail from the error object
            _OrderNotFoundFaultType* orderNotFound;
            hr = WsGetFaultErrorDetail(
                error,
                &orderNotFoundFaultTypeDescription,
                WS_READ_OPTIONAL_POINTER,
                heap,
                &orderNotFound,
                sizeof(orderNotFound));
                
            if (FAILED(hr))
            {
                goto Exit;
            }
        
            if (orderNotFound != NULL)
            {
                // Print out the fault detail
                wprintf(L"Order %lu was not found\n", orderNotFound->orderID);
            }
        
            // Reset error so it can be used again
            hr = WsResetError(error);
            if (FAILED(hr))
            {
                goto Exit;
            }
        }
        
        if (FAILED(hr))
        {
            goto Exit;
        }
        
        // Reset the message so it can be used again
        hr = WsResetMessage(requestMessage, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
        
        // Reset the message so it can be used again
        hr = WsResetMessage(replyMessage, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
        
        wprintf(L"\n");
        
        // Reset the heap
        hr = WsResetHeap(heap, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
    }
    
Exit:
    if (FAILED(hr))
    {
        // Print out the error
        PrintError(hr, error);
    }
    fflush(
        stdout);
    
    if (channel != NULL)
    {
        // Close the channel
        WsCloseChannel(channel, NULL, error);
    }
    if (requestMessage != NULL)
    {
        WsFreeMessage(requestMessage);
    }
    if (replyMessage != NULL)
    {
        WsFreeMessage(replyMessage);
    }
    if (channel != NULL)
    {
        WsFreeChannel(channel);
    }
    
    
    if (error != NULL)
    {
        WsFreeError(error);
    }
    if (heap != NULL)
    {
        WsFreeHeap(heap);
    }
    fflush(stdout);
    return SUCCEEDED(hr) ? 0 : -1;
}


```



## PurchaseOrder.wsdl

``` syntax
<wsdl:definitions 
    xmlns:soap="https://schemas.xmlsoap.org/wsdl/soap/" 
    xmlns:tns="https://example.org" 
    xmlns:xsd="https://www.w3.org/2001/XMLSchema" 
    xmlns:wsaw="https://www.w3.org/2006/05/addressing/wsdl" 
    xmlns:soap12="https://schemas.xmlsoap.org/wsdl/soap12/" 
    xmlns:wsdl="https://schemas.xmlsoap.org/wsdl/" 
    targetNamespace="https://example.org">
    <wsdl:types>
        <xsd:schema targetNamespace="https://example.org" elementFormDefault="qualified">
            <xsd:element name="PurchaseOrderType">
                <xsd:complexType>
                    <xsd:sequence>
                        <xsd:element minOccurs="0" name="quantity" type="xsd:int"/>
                        <xsd:element minOccurs="0" name="productName" type="xsd:string"/>
                    </xsd:sequence>
                </xsd:complexType>
            </xsd:element>
            <xsd:element name="OrderConfirmationType">
                <xsd:complexType>
                    <xsd:sequence>
                        <xsd:element minOccurs="0" name="orderID" type="xsd:unsignedInt"/>
                        <xsd:element minOccurs="0" name="expectedShipDate" type="xsd:string"/>
                    </xsd:sequence>
                </xsd:complexType>
            </xsd:element>
            <xsd:element name="GetOrderStatusType">
                <xsd:complexType>
                    <xsd:sequence>
                        <xsd:element minOccurs="0" name="orderID" type="xsd:unsignedInt"/>
                    </xsd:sequence>
                </xsd:complexType>
            </xsd:element>
            <xsd:element name="GetOrderStatusResponseType">
                <xsd:complexType>
                    <xsd:sequence>
                        <xsd:element minOccurs="0" name="orderID" type="xsd:unsignedInt"/>
                        <xsd:element minOccurs="0" name="status" type="xsd:string"/>
                    </xsd:sequence>
                </xsd:complexType>
            </xsd:element>
            <xsd:element name="OrderNotFoundFaultType">
                <xsd:complexType>
                    <xsd:sequence>
                        <xsd:element minOccurs="0" name="orderID" type="xsd:unsignedInt"/>
                    </xsd:sequence>
                </xsd:complexType>
            </xsd:element>
        </xsd:schema>
    </wsdl:types>
    <wsdl:message name="PurchaseOrder">
        <wsdl:part name="parameters" element="tns:PurchaseOrderType"/>
    </wsdl:message>
    <wsdl:message name="OrderConfirmation">
        <wsdl:part name="parameters" element="tns:OrderConfirmationType"/>
    </wsdl:message>
    <wsdl:message name="GetOrderStatus">
        <wsdl:part name="parameters" element="tns:GetOrderStatusType"/>
    </wsdl:message>
    <wsdl:message name="GetOrderStatusResponse">
        <wsdl:part name="parameters" element="tns:GetOrderStatusResponseType"/>
    </wsdl:message>
    <wsdl:message name="OrderNotFoundFault">
        <wsdl:part name="parameters" element="tns:OrderNotFoundFaultType"/>
    </wsdl:message>
    <wsdl:portType name="IPurchaseOrder">
        <wsdl:operation name="Order">
            <wsdl:input message="tns:PurchaseOrder" wsaw:Action="https://example.org/purchaseorder"/>
            <wsdl:output message="tns:OrderConfirmation" wsaw:Action="https://example.org/orderconfirmation"/>
        </wsdl:operation>
        <wsdl:operation name="OrderStatus">
            <wsdl:input message="tns:GetOrderStatus" wsaw:Action="https://example.org/getorderstatus"/>
            <wsdl:output message="tns:GetOrderStatusResponse" wsaw:Action="https://example.org/getorderstatusresponse"/>
            <wsdl:fault name="OrderNotFound" message="tns:OrderNotFoundFault" wsaw:Action="https://example.org/ordernotfound"/>
        </wsdl:operation>
    </wsdl:portType>
    <wsdl:binding name="PurchaseOrderBinding" type="tns:IPurchaseOrder">
        <soap:binding transport="https://schemas.xmlsoap.org/soap/http"/>
        <wsdl:operation name="Order">
            <soap:operation soapAction="https://example.org/purchaseorder" style="document"/>
            <wsdl:input>
                <soap:body use="literal"/>
            </wsdl:input>
            <wsdl:output>
                <soap:body use="literal"/>
            </wsdl:output>
        </wsdl:operation>
        <wsdl:operation name="OrderStatus">
            <soap:operation soapAction="https://example.org/getorderstatus" style="document"/>
            <wsdl:input>
                <soap:body use="literal"/>
            </wsdl:input>
            <wsdl:output>
                <soap:body use="literal"/>
            </wsdl:output>
            <wsdl:fault name="OrderNotFound">
                <soap:body use="literal"/>
            </wsdl:fault>
        </wsdl:operation>
    </wsdl:binding>
    <wsdl:service name="PurchaseOrderService">
        <wsdl:port name="IPurchaseOrder" binding="tns:PurchaseOrderBinding">
            <soap:address location="https://example.org/IPurchaseOrder"/>
        </wsdl:port>
    </wsdl:service>
</wsdl:definitions>
```

## Makefile

``` syntax
#------------------------------------------------------------
# Copyright (C) Microsoft.  All rights reserved.
#------------------------------------------------------------

!include <Win32.Mak>

EXTRA_LIBS = WebServices.lib rpcrt4.lib Iphlpapi.lib

all: $(OUTDIR) $(OUTDIR)\WsHttpClientWithKerberosOverSsl.exe

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"
    
$(OUTDIR)\PurchaseOrder.wsdl.c: PurchaseOrder.wsdl
     Wsutil.exe /wsdl:PurchaseOrder.wsdl /string:WS_STRING /out:$(OUTDIR)
    

$(OUTDIR)\PurchaseOrder.wsdl.obj: $(OUTDIR)\PurchaseOrder.wsdl.c
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX -I$(OUTDIR) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(OUTDIR)\PurchaseOrder.wsdl.c

$(OUTDIR)\HttpClientWithKerberosOverSsl.obj: HttpClientWithKerberosOverSsl.cpp $(OUTDIR)\PurchaseOrder.wsdl.c
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX -I$(OUTDIR) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" HttpClientWithKerberosOverSsl.cpp

$(OUTDIR)\WsHttpClientWithKerberosOverSsl.exe: $(OUTDIR)\HttpClientWithKerberosOverSsl.obj $(OUTDIR)\PurchaseOrder.wsdl.obj
    $(link) $(ldebug) $(conlflags) $(conlibsmt) $(EXTRA_LIBS) -out:$(OUTDIR)\WsHttpClientWithKerberosOverSsl.exe $(OUTDIR)\HttpClientWithKerberosOverSsl.obj $(OUTDIR)\PurchaseOrder.wsdl.obj /PDB:$(OUTDIR)\WsHttpClientWithKerberosOverSsl.PDB

clean:
    $(CLEANUP)
```

 

 




