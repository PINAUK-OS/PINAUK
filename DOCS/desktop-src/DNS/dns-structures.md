---
title: DNS structures
description: The following structures are defined for use with DNS.
ms.assetid: 636399be-43a5-4ddf-b652-f8efb81fbf42
keywords:
- Domain Name System Structures
- DNS Structures
- Domain Name System, reference, structures
ms.topic: reference
ms.date: 04/19/2019
---

# DNS structures

The following structures are defined for use with DNS.

- [**DNS_ADDR**](/windows/win32/api/windnsdef/ns-windnsdef-dns_addr)
- [**DNS_ADDR_ARRAY**](/windows/win32/api/windnsdef/ns-windnsdef-dns_addr_array)
- [**DNS_APPLICATION_SETTINGS**](/windows/win32/api/windns/ns-windns-dns_application_settings)
- [**DNS_CUSTOM_SERVER**](/windows/win32/api/windnsdef/ns-windnsdef-dns_custom_server)
- [**DNS_HEADER**](/windows/win32/api/windnsdef/ns-windnsdef-dns_header)
- [**DNS_MESSAGE_BUFFER**](/windows/win32/api/windnsdef/ns-windnsdef-dns_message_buffer)
- [**DNS_PROXY_INFORMATION**](/windows/win32/api/windns/ns-windns-dns_proxy_information)
- [**DNS_QUERY_CANCEL**](/windows/win32/api/windns/ns-windns-dns_query_cancel)
- [**DNS_QUERY_RAW_CANCEL**](/windows/win32/api/windns/ns-windns-dns_query_raw_cancel)
- [**DNS_QUERY_RAW_REQUEST**](/windows/win32/api/windns/ns-windns-dns_query_raw_request)
- [**DNS_QUERY_RAW_RESULT**](/windows/win32/api/windns/ns-windns-dns_query_raw_result)
- [**DNS_QUERY_REQUEST**](/windows/win32/api/windns/ns-windns-dns_query_request)
- [**DNS_QUERY_REQUEST3**](/windows/win32/api/windns/ns-windns-dns_query_request3)
- [**DNS_QUERY_RESULT**](/windows/win32/api/windns/ns-windns-dns_query_result)
- [**DNS_RECORD**](/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)
- [**DNS_RECORD_FLAGS**](/windows/win32/api/windnsdef/ns-windnsdef-dns_record_flags)
- [**DNS_SERVICE_BROWSE_REQUEST**](/windows/win32/api/windns/ns-windns-dns_service_browse_request)
- [**DNS_SERVICE_CANCEL**](/windows/win32/api/windns/ns-windns-dns_service_cancel)
- [**DNS_SERVICE_INSTANCE**](/windows/win32/api/windns/ns-windns-dns_service_instance)
- [**DNS_SERVICE_REGISTER_REQUEST**](/windows/win32/api/windns/ns-windns-dns_service_register_request)
- [**DNS_SERVICE_RESOLVE_REQUEST**](/windows/win32/api/windns/ns-windns-dns_service_resolve_request)
- [**IP4_ARRAY**](/windows/win32/api/windns/ns-windns-ip4_array)
- [**IP6_ADDRESS**](/windows/win32/api/windnsdef/ns-windnsdef-ip6_address)
- [**MDNS_QUERY_HANDLE**](/windows/win32/api/windns/ns-windns-mdns_query_handle)
- [**MDNS_QUERY_REQUEST**](/windows/win32/api/windns/ns-windns-mdns_query_request)

The following Resource Record (RR) structures are also included in the DNS API. These structures are used with the **DNS_RECORD** structure to programmatically manage DNS resource records.

- [**DNS_A_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_a_data)
- [**DNS_AAAA_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_aaaa_data)
- [**DNS_ATMA_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_atma_data)
- [**DNS_DHCID_DATA**](/windows/win32/api/windns/ns-windns-dns_dhcid_data)
- [**DNS_DNSKEY_DATA**](/previous-versions/windows/desktop/legacy/dd392295(v=vs.85))
- [**DNS_DS_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_ds_data)
- [**DNS_KEY_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_key_data)
- [**DNS_LOC_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_loc_data)
- [**DNS_MINFO_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_minfo_dataw)
- [**DNS_MX_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_mx_dataa)
- [**DNS_NAPTR_DATA**](/windows/win32/api/windns/ns-windns-dns_naptr_dataw)
- [**DNS_NSEC_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_nsec_dataw)
- [**DNS_NULL_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_null_data)
- [**DNS_NXT_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_nxt_dataw)
- [**DNS_OPT_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_opt_data)
- [**DNS_PTR_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_ptr_dataw)
- [**DNS_RRSET**](/windows/win32/api/windns/ns-windns-dns_rrset)
- [**DNS_RRSIG_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_sig_dataw)
- [**DNS_SIG_DATA**](/previous-versions/windows/desktop/legacy/ms682094(v=vs.85))
- [**DNS_SOA_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_soa_dataw)
- [**DNS_SRV_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_srv_dataw)
- [**DNS_TKEY_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_tkey_dataw)
- [**DNS_TSIG_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_tsig_dataw)
- [**DNS_TXT_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_txt_dataw)
- [**DNS_WINS_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_wins_data)
- [**DNS_WINSR_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_winsr_dataw)
- [**DNS_WIRE_QUESTION**](/windows/win32/api/windns/ns-windns-dns_wire_question)
- [**DNS_WIRE_RECORD**](/windows/win32/api/windns/ns-windns-dns_wire_record)
- [**DNS_WKS_DATA**](/windows/win32/api/windnsdef/ns-windnsdef-dns_wks_data)
