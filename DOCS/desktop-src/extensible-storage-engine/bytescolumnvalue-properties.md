---
description: "Learn more about: BytesColumnValue properties"
title: BytesColumnValue properties
TOCTitle: BytesColumnValue properties
ms:assetid: Properties.T:Microsoft.Isam.Esent.Interop.BytesColumnValue
ms:mtpsurl: https://msdn.microsoft.com/library/microsoft.isam.esent.interop.bytescolumnvalue_properties(v=EXCHG.10)
ms:contentKeyID: 55100964
ms.date: 07/30/2014
ms.topic: reference
---

# BytesColumnValue properties

Include protected members  
Include inherited members  

The [BytesColumnValue](./bytescolumnvalue-class.md) type exposes the following members.

## Properties

<table>
<thead>
<tr class="header">
<th> </th>
<th>Name</th>
<th>Description</th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td><img src="../images/dn292128.pubproperty(exchg.10).gif" title="Public property" alt="Public property" /></td>
<td><a href="dn334166(v=exchg.10).md">Columnid</a></td>
<td>Gets or sets the columnid to be set or retrieved. (Inherited from <a href="dn334206(v=exchg.10).md">ColumnValue</a>.)</td>
</tr>
<tr class="even">
<td><img src="../images/dn292128.pubproperty(exchg.10).gif" title="Public property" alt="Public property" /></td>
<td><a href="dn334212(v=exchg.10).md">Error</a></td>
<td>Gets the warning generated by retrieving or setting this column. (Inherited from <a href="dn334206(v=exchg.10).md">ColumnValue</a>.)</td>
</tr>
<tr class="odd">
<td><img src="../images/dn292128.pubproperty(exchg.10).gif" title="Public property" alt="Public property" /></td>
<td><a href="dn334165(v=exchg.10).md">ItagSequence</a></td>
<td>Gets or sets the column itag sequence. (Inherited from <a href="dn334206(v=exchg.10).md">ColumnValue</a>.)</td>
</tr>
<tr class="even">
<td><img src="../images/dn292128.pubproperty(exchg.10).gif" title="Public property" alt="Public property" /></td>
<td><a href="dn334126(v=exchg.10).md">Length</a></td>
<td>Gets the byte length of a column value, which is zero if column is null, otherwise matches the actual length of the byte array. (Overrides <a href="dn334213(v=exchg.10).md">ColumnValue.Length</a>.)</td>
</tr>
<tr class="odd">
<td><img src="../images/dn292128.pubproperty(exchg.10).gif" title="Public property" alt="Public property" /></td>
<td><a href="dn334169(v=exchg.10).md">RetrieveGrbit</a></td>
<td>Gets or sets column retrieval options. (Inherited from <a href="dn334206(v=exchg.10).md">ColumnValue</a>.)</td>
</tr>
<tr class="even">
<td><img src="../images/dn292128.pubproperty(exchg.10).gif" title="Public property" alt="Public property" /></td>
<td><a href="dn334215(v=exchg.10).md">SetGrbit</a></td>
<td>Gets or sets column update options. (Inherited from <a href="dn334206(v=exchg.10).md">ColumnValue</a>.)</td>
</tr>
<tr class="odd">
<td><img src="../images/dn292128.protproperty(exchg.10).gif" title="Protected property" alt="Protected property" /></td>
<td><a href="dn334176(v=exchg.10).md">Size</a></td>
<td>Gets the size of the value in the column. This returns 0 for variable sized columns (i.e. binary and string). (Overrides <a href="dn334172(v=exchg.10).md">ColumnValue.Size</a>.)</td>
</tr>
<tr class="even">
<td><img src="../images/dn292128.pubproperty(exchg.10).gif" title="Public property" alt="Public property" /></td>
<td><a href="dn334129(v=exchg.10).md">Value</a></td>
<td>Gets or sets the value of the column. Use <a href="dn334138(v=exchg.10).md">SetColumns(JET_SESID, JET_TABLEID, [])</a> to update a record with the column value.</td>
</tr>
<tr class="odd">
<td><img src="../images/dn292128.pubproperty(exchg.10).gif" title="Public property" alt="Public property" /></td>
<td><a href="dn334177(v=exchg.10).md">ValueAsObject</a></td>
<td>Gets the last set or retrieved value of the column. The value is returned as a generic object. (Overrides <a href="dn334214(v=exchg.10).md">ColumnValue.ValueAsObject</a>.)</td>
</tr>
</tbody>
</table>


Top

## See also

#### Reference

[BytesColumnValue class](./bytescolumnvalue-class.md)

[Microsoft.Isam.Esent.Interop namespace](./microsoft.isam.esent.interop-namespace.md)
