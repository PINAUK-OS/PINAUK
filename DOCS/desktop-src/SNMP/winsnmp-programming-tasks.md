---
title: WinSNMP Programming Tasks
description: The following table summarizes the basic programming procedures that you must perform to code a WinSNMP application, and the topics that provide information about these tasks.
ms.assetid: '70c24042-bf44-4484-8e5e-d117e2ba28d5'
ms.topic: concept-article
ms.date: 05/31/2018
---

# WinSNMP Programming Tasks

The following table summarizes the basic programming procedures that you must perform to code a WinSNMP application, and the topics that provide information about these tasks.




| Programming task | Task-related function and topics | 
|------------------|----------------------------------|
| Open the WinSNMP application. | Use <a href="/windows/desktop/api/Winsnmp/nf-winsnmp-snmpstartup"><strong>SnmpStartup</strong></a>. See <a href="opening-and-closing-a-winsnmp-application.md">Opening and Closing a WinSNMP Application</a>.<br /> | 
| Open one or more WinSNMP sessions. | Use <a href="/windows/desktop/api/Winsnmp/nf-winsnmp-snmpcreatesession"><strong>SnmpCreateSession</strong></a>. See <a href="opening-and-closing-a-winsnmp-session.md">Opening and Closing a WinSNMP Session</a>.<br /> | 
| Register to receive traps or notifications. | Use <a href="/windows/desktop/api/Winsnmp/nf-winsnmp-snmpregister"><strong>SnmpRegister</strong></a>. See <a href="managing-traps-and-notifications.md">Managing Traps and Notifications</a>.<br /> | 
| Create one or more variable binding lists for incorporation in a PDU. | Use [**SnmpCreateVbl**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpcreatevbl), [**SnmpDuplicateVbl**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpduplicatevbl), [**SnmpSetVb**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpsetvb). See [Working with Variable Binding Lists](working-with-variable-binding-lists.md).<br> **Note:** The application may need to call other [variable binding functions](winsnmp-functions.md) to create the variable binding list.<br> | 
| Create one or more PDUs for transmission and processing. | Use [**SnmpCreatePDU**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpcreatepdu), [**SnmpSetPduData**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpsetpdudata), [**SnmpDuplicatePDU**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpduplicatepdu). See [Working with Protocol Data Units](working-with-protocol-data-units.md).<br> **Note:** The application may need to call other [PDU functions](winsnmp-functions.md) and WinSNMP [utility functions](winsnmp-functions.md) to create the PDU.<br> | 
| Submit one or more SNMP operation requests. | Use <a href="/windows/desktop/api/Winsnmp/nf-winsnmp-snmpsendmsg"><strong>SnmpSendMsg</strong></a>. See <a href="sending-snmp-messages.md">Sending SNMP Messages</a>.<br /> | 
| Retrieve the response to the SNMP operation request. | Use <a href="/windows/desktop/api/Winsnmp/nf-winsnmp-snmprecvmsg"><strong>SnmpRecvMsg</strong></a>. See <a href="receiving-snmp-messages.md">Receiving SNMP Messages</a>.<br /> | 
| Process the request response. | Use application-specific logic. | 
| Close each WinSNMP session. | Use <a href="/windows/desktop/api/Winsnmp/nf-winsnmp-snmpclose"><strong>SnmpClose</strong></a>. See <a href="opening-and-closing-a-winsnmp-session.md">Opening and Closing a WinSNMP Session</a>.<br /> | 
| Close the WinSNMP application. | Use <a href="/windows/desktop/api/Winsnmp/nf-winsnmp-snmpcleanup"><strong>SnmpCleanup</strong></a>. See <a href="opening-and-closing-a-winsnmp-application.md">Opening and Closing a WinSNMP Application</a>.<br /> | 




 

The following topics contain additional information about other general programming concepts specific to the WinSNMP environment.



| Topic                                                              | Concepts                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
|--------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [General programming tasks](general-winsnmp-programming-tasks.md) | [Managing Object Identifiers](managing-object-identifiers.md)[Freeing WinSNMP Descriptors](freeing-winsnmp-descriptors.md)<br/> [Setting the Entity and Context Translation Mode](setting-the-entity-and-context-translation-mode.md)<br/> [Managing the Retransmission Policy](managing-the-retransmission-policy.md)<br/> [Writing WinSNMP Applications with Multiple Threads](writing-winsnmp-applications-with-multiple-threads.md)<br/> [Registering an SNMP Agent Application](registering-an-snmp-agent-application.md)<br/> |



 

In addition, the WinSNMP application may need to incorporate calls to the following WinSNMP functions: [**SnmpFreeVbl**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpfreevbl), [**SnmpFreeEntity**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpfreeentity), [**SnmpFreeDescriptor**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpfreedescriptor), [**SnmpFreeContext**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpfreecontext), and [**SnmpFreePdu**](/windows/desktop/api/Winsnmp/nf-winsnmp-snmpfreepdu). This enables the Microsoft WinSNMP implementation to free WinSNMP memory objects. As a general rule, the WinSNMP application should free all resources allocated as the result of a call to a WinSNMP function. For additional information about deallocating resources, see [Allocating WinSNMP Memory Objects](allocating-winsnmp-memory-objects.md).

 

 





