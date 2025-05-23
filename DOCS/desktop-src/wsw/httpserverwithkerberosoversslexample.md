---
title: HttpServerWithKerberosOverSslExample
description: This example shows a TCP server that accepts a channel and receives and replies to messages, with kerberos over SSL mixed-mode security.
ms.assetid: 2910f594-2f38-4c1e-bb47-89258b752572
keywords:
- HttpServerWithKerberosOverSslExample Native-Web-Services
- WWSAPI
- WWS
ms.topic: reference
ms.date: 05/31/2018
---

# HttpServerWithKerberosOverSslExample

This example shows a TCP server that accepts a channel and receives and replies to messages, with kerberos over SSL mixed-mode security. In this setup, the transport connection is protected (signed, encrypted) by SSL which also provides server authentication. Client authentication is provided by a kerberos APREQ ticket in a WS-Security header in the message.

-   [HttpServerWithKerberosOverSsl.cpp](#httpserverwithkerberosoversslcpp)
-   [PurchaseOrder.wsdl](#purchaseorderwsdl)
-   [Makefile](#makefile)

## HttpServerWithKerberosOverSsl.cpp


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



// The following is used as the action value for purchasing fault messages
static WS_XML_STRING purchasingFaultAction = WS_XML_STRING_VALUE("http://example.org/purchasingfault");

// Indicates a fault will be serialized in the body of the message
static WS_ELEMENT_DESCRIPTION purchasingFaultElement =
{
    NULL,
    NULL,
    WS_FAULT_TYPE,
    NULL,
};

// The description of the fault message
static WS_MESSAGE_DESCRIPTION purchasingFaultMessageDescription =
{
    &purchasingFaultAction,
    &purchasingFaultElement,
};

// Main entry point
int __cdecl wmain(int argc, __in_ecount(argc) wchar_t **argv)
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);
    
    HRESULT hr = NOERROR;
    WS_ERROR* error = NULL;
    WS_LISTENER* listener = NULL;
    WS_CHANNEL* channel = NULL;
    WS_MESSAGE* requestMessage = NULL;
    WS_MESSAGE* replyMessage = NULL;
    WS_HEAP* heap = NULL;
    
$$RC_START_HIGHLIGHT
    // declare and initialize a kerberos APREQ message security binding
    WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING kerberosBinding = {}; // zero out the struct
    kerberosBinding.binding.bindingType = WS_KERBEROS_APREQ_MESSAGE_SECURITY_BINDING_TYPE; // set the binding type
    kerberosBinding.bindingUsage = WS_SUPPORTING_MESSAGE_SECURITY_USAGE; // set the binding usage
    
    // declare and initialize an SSL transport security binding
    WS_SSL_TRANSPORT_SECURITY_BINDING sslBinding = {}; // zero out the struct
    sslBinding.binding.bindingType = WS_SSL_TRANSPORT_SECURITY_BINDING_TYPE; // set the binding type
    // NOTE: At the server, the SSL certificate for the listen URI must be
    // registered with http.sys using a tool such as httpcfg.exe.
    
    // declare and initialize the array of all security bindings
    WS_SECURITY_BINDING* securityBindings[2] = { &sslBinding.binding, &kerberosBinding.binding };
    
    // declare and initialize the security description
    WS_SECURITY_DESCRIPTION securityDescription = {}; // zero out the struct
    securityDescription.securityBindings = securityBindings;
    securityDescription.securityBindingCount = WsCountOf(securityBindings);
$$RC_END_HIGHLIGHT
    
    WS_STRING uri = WS_STRING_VALUE(L"https://localhost:8443/example");
    
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
    // Create a listener
    hr = WsCreateListener(
        WS_CHANNEL_TYPE_REPLY, 
        WS_HTTP_CHANNEL_BINDING, 
        NULL, 0, 
        &securityDescription, 
        &listener, 
        error);
    if (FAILED(hr))
    {
        goto Exit;
    }
$$RC_END_HIGHLIGHT
    
    // Open listener 
    hr = WsOpenListener(listener, &uri, NULL, error);
    if (FAILED(hr))
    {
        goto Exit;
    }
    
    hr = WsCreateChannelForListener(
        listener, 
        NULL, 
        0, 
        &channel, 
        error);
    if (FAILED(hr))
    {
        goto Exit;
    }
    
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
    
    
    // Receive requests / send replies
    for (int i = 0; i < 300; i++)
    {
        // Accept a request from the client
        hr = WsAcceptChannel(listener, channel, NULL, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
    
        // Set up the descriptions of the expected messages. We expect either a purchase order
        // or a request for order status.
        const WS_MESSAGE_DESCRIPTION* requestMessageDescriptions[] = 
        { 
            &PurchaseOrder_wsdl.messages.PurchaseOrder,   // contains a _PurchaseOrderType in the body
            &PurchaseOrder_wsdl.messages.GetOrderStatus,  // contains a GetOrderStatus in the body
        };
        
        // Receive the message and deserialize the element of the body into the appropriate
        // structure, based on the message descriptions.  The value of the body will be 
        // allocated in the specified WS_HEAP, and are valid until WsResetHeap is called.
        void* requestBodyPointer;
        ULONG indexOfMatchedMessageDescription;
        WS_STRING orderStatus = WS_STRING_VALUE(L"Pending");
        WS_STRING shipDate1 = WS_STRING_VALUE(L"1/1/2006");
        
        hr = WsReceiveMessage(channel, requestMessage, requestMessageDescriptions, WsCountOf(requestMessageDescriptions),
            WS_RECEIVE_REQUIRED_MESSAGE, WS_READ_REQUIRED_POINTER, heap, 
            &requestBodyPointer, sizeof(requestBodyPointer), &indexOfMatchedMessageDescription, NULL, error);
        
        // Process the request, and generate the reply
        const WS_MESSAGE_DESCRIPTION* replyMessageDescription = NULL;
        const void* replyBodyPointer = NULL;
        ULONG replyBodySize = 0;
        _OrderConfirmationType orderConfirmation;
        _GetOrderStatusResponseType getOrderStatusResponse;
        
        if (SUCCEEDED(hr))
        {
            // Get the message description that matched
            const WS_MESSAGE_DESCRIPTION* requestMessageDescription = requestMessageDescriptions[indexOfMatchedMessageDescription];
        
            if (requestMessageDescription == &PurchaseOrder_wsdl.messages.PurchaseOrder)
            {
                // The message was a purchase order.  Get the pointer to the deserialized value.
                _PurchaseOrderType* purchaseOrder = (_PurchaseOrderType*)requestBodyPointer;
        
                // Print out purchase order contents
                wprintf(L"%lu, %.*s\n", 
                    purchaseOrder->quantity, 
                    purchaseOrder->productName.length,
                    purchaseOrder->productName.chars);
        
                // Initialize order confirmation data
                orderConfirmation.expectedShipDate = shipDate1;
                orderConfirmation.orderID = 123;
        
                // Setup up reply message
                replyMessageDescription = &PurchaseOrder_wsdl.messages.OrderConfirmation;
                replyBodyPointer = &orderConfirmation;
                replyBodySize = sizeof(orderConfirmation);
            }
            else if (requestMessageDescription == &PurchaseOrder_wsdl.messages.GetOrderStatus)
            {
                // The message was an order status request.  Get the pointer to the deserialized value.
                _GetOrderStatusType* getOrderStatus = (_GetOrderStatusType*)requestBodyPointer;
        
                // Generate a fault if we don't recognize the order ID
                if (getOrderStatus->orderID != 123)
                {
                    // Fill out details about the fault
                    _OrderNotFoundFaultType orderNotFound;
                    orderNotFound.orderID = getOrderStatus->orderID;
                    
                    // TODO: the following should be removed when wsutil generates it
                    WS_XML_STRING _faultDetailName = WS_XML_STRING_VALUE("OrderNotFound");
                    WS_XML_STRING _faultDetailNs = WS_XML_STRING_VALUE("http://example.com");
                    WS_XML_STRING _faultAction = WS_XML_STRING_VALUE("http://example.com/fault");
                    WS_ELEMENT_DESCRIPTION _faultElementDescription = { &_faultDetailName, &_faultDetailNs, WS_UINT32_TYPE, NULL };
                    WS_FAULT_DETAIL_DESCRIPTION orderNotFoundFaultTypeDescription = { &_faultAction, &_faultElementDescription };
                    
                    // Set fault detail information in the error object
                    hr = WsSetFaultErrorDetail(
                        error,
                        &orderNotFoundFaultTypeDescription,
                        WS_WRITE_REQUIRED_VALUE,
                        &orderNotFound,
                        sizeof(orderNotFound));
                    
                    if (FAILED(hr))
                    {
                        goto Exit;
                    }
                    
                    // Add an error string to the error object.  This string will
                    // be included in the fault that is sent.
                    WS_STRING errorMessage = WS_STRING_VALUE(L"Invalid order ID");
                    hr = WsAddErrorString(error, &errorMessage);
                    
                    if (FAILED(hr))
                    {
                        goto Exit;
                    }
        
                    // Use a failure code to indicate that a fault should be sent
                    hr = E_FAIL;
                }
                else
                {
                    // Initialize the order status response
                    getOrderStatusResponse.orderID = getOrderStatus->orderID;
                    getOrderStatusResponse.status = orderStatus;
        
                    // Specify which message description to use for reply
                    replyMessageDescription = &PurchaseOrder_wsdl.messages.GetOrderStatusResponse;
                    replyBodyPointer = &getOrderStatusResponse;
                    replyBodySize = sizeof(getOrderStatusResponse);
                }
            }
        }
        
        // If there was an error receiving the message
        if (FAILED(hr))
        {
            // Send a fault in the body of the reply message.  The information
            // accumulated in the error object is used to populate the fault.
            // The error code is not transmitted but instead is used to
            // generate an error string if no error strings are present in the
            // error object.
            hr = WsSendFaultMessageForError(
                channel, 
                replyMessage, 
                error,
                hr,
                WS_FULL_FAULT_DISCLOSURE,
                requestMessage, 
                NULL, 
                error);
        
            if (FAILED(hr))
            {
                goto Exit;
            }
        
            // Reset the error so it can be used again
            hr = WsResetError(error);
            if (FAILED(hr))
            {
                goto Exit;
            }
        
            // Reset the reply message so it can be used again
            hr = WsResetMessage(replyMessage, error);
            if (FAILED(hr))
            {
                goto Exit;
            }
        }
        else
        {
            // Send a reply message
            hr = WsSendReplyMessage(
                channel, 
                replyMessage, 
                replyMessageDescription, 
                WS_WRITE_REQUIRED_VALUE,
                replyBodyPointer, 
                replyBodySize,
                requestMessage, 
                NULL, 
                error);
        
            if (FAILED(hr))
            {
                goto Exit;
            }
        
            // Reset the reply message so it can be used again
            hr = WsResetMessage(replyMessage, error);
            if (FAILED(hr))
            {
                goto Exit;
            }
        }
        
        // Reset the request message so it can be used again
        hr = WsResetMessage(requestMessage, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
        
        // Reset the heap, which will free any allocations made on it
        hr = WsResetHeap(heap, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
    
        // Close the request
        hr = WsCloseChannel(channel, NULL, error);
        if (FAILED(hr))
        {
            goto Exit;
        }
    
        // Prepare channel for reuse
        hr = WsResetChannel(channel, error);
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
    if (channel != NULL)
    {
        WsFreeChannel(channel);
    }
    if (requestMessage != NULL)
    {
        WsFreeMessage(requestMessage);
    }
    if (replyMessage != NULL)
    {
        WsFreeMessage(replyMessage);
    }
    if (listener != NULL)
    {
        // Close the listener if it was opened
        WsCloseListener(listener, NULL, error);
    }
    if (listener != NULL)
    {
        WsFreeListener(listener);
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
    xmlns:soap="http://schemas.xmlsoap.org/wsdl/soap/" 
    xmlns:tns="http://example.org" 
    xmlns:xsd="http://www.w3.org/2001/XMLSchema" 
    xmlns:wsaw="http://www.w3.org/2006/05/addressing/wsdl" 
    xmlns:soap12="http://schemas.xmlsoap.org/wsdl/soap12/" 
    xmlns:wsdl="http://schemas.xmlsoap.org/wsdl/" 
    targetNamespace="http://example.org">
    <wsdl:types>
        <xsd:schema targetNamespace="http://example.org" elementFormDefault="qualified">
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
            <wsdl:input message="tns:PurchaseOrder" wsaw:Action="http://example.org/purchaseorder"/>
            <wsdl:output message="tns:OrderConfirmation" wsaw:Action="http://example.org/orderconfirmation"/>
        </wsdl:operation>
        <wsdl:operation name="OrderStatus">
            <wsdl:input message="tns:GetOrderStatus" wsaw:Action="http://example.org/getorderstatus"/>
            <wsdl:output message="tns:GetOrderStatusResponse" wsaw:Action="http://example.org/getorderstatusresponse"/>
            <wsdl:fault name="OrderNotFound" message="tns:OrderNotFoundFault" wsaw:Action="http://example.org/ordernotfound"/>
        </wsdl:operation>
    </wsdl:portType>
    <wsdl:binding name="PurchaseOrderBinding" type="tns:IPurchaseOrder">
        <soap:binding transport="http://schemas.xmlsoap.org/soap/http"/>
        <wsdl:operation name="Order">
            <soap:operation soapAction="http://example.org/purchaseorder" style="document"/>
            <wsdl:input>
                <soap:body use="literal"/>
            </wsdl:input>
            <wsdl:output>
                <soap:body use="literal"/>
            </wsdl:output>
        </wsdl:operation>
        <wsdl:operation name="OrderStatus">
            <soap:operation soapAction="http://example.org/getorderstatus" style="document"/>
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
            <soap:address location="http://example.org/IPurchaseOrder"/>
        </wsdl:port>
    </wsdl:service>
</wsdl:definitions>
```

## Makefile

``` syntax
!include <Win32.Mak>

EXTRA_LIBS = WebServices.lib rpcrt4.lib Iphlpapi.lib

all: $(OUTDIR) $(OUTDIR)\WsHttpServerWithKerberosOverSsl.exe

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"
    
$(OUTDIR)\PurchaseOrder.wsdl.c: PurchaseOrder.wsdl
     Wsutil.exe /wsdl:PurchaseOrder.wsdl /string:WS_STRING /out:$(OUTDIR)
    
$(OUTDIR)\PurchaseOrder.wsdl.obj: $(OUTDIR)\PurchaseOrder.wsdl.c
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX -I$(OUTDIR) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(OUTDIR)\PurchaseOrder.wsdl.c

$(OUTDIR)\HttpServerWithKerberosOverSsl.obj: HttpServerWithKerberosOverSsl.cpp $(OUTDIR)\PurchaseOrder.wsdl.c
    $(cc) $(cdebug) $(cflags) $(cvarsmt) /WX -I$(OUTDIR) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" HttpServerWithKerberosOverSsl.cpp

$(OUTDIR)\WsHttpServerWithKerberosOverSsl.exe: $(OUTDIR)\HttpServerWithKerberosOverSsl.obj $(OUTDIR)\PurchaseOrder.wsdl.obj
    $(link) $(ldebug) $(conlflags) $(conlibsmt) $(EXTRA_LIBS) -out:$(OUTDIR)\WsHttpServerWithKerberosOverSsl.exe $(OUTDIR)\HttpServerWithKerberosOverSsl.obj $(OUTDIR)\PurchaseOrder.wsdl.obj /PDB:$(OUTDIR)\WsHttpServerWithKerberosOverSsl.PDB

clean:
    $(CLEANUP)
```

 

 




