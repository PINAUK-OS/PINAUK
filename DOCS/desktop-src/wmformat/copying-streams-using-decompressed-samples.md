---
title: Copying Streams Using Decompressed Samples
description: Copying Streams Using Decompressed Samples
ms.assetid: 03ad8415-1dff-4362-94b4-7ec69c3e7888
keywords:
- Windows Media Format SDK,copying streams
- Advanced Systems Format (ASF),copying streams
- ASF (Advanced Systems Format),copying streams
- streams,copying using decompressed data
ms.topic: concept-article
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Copying Streams Using Decompressed Samples

\[The feature associated with this page, [Windows Media Format 11 SDK](/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](/windows/win32/medfound/source-reader) and [Sink Writer](/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

It is strongly recommended that you not copy streams from one file to another using decompressed samples. The process of decompressing and recompressing samples will degrade the quality of the output. If you do need to decompress your samples and then copy them to another stream, you may encounter some difficulty with quality-based variable bit rate (VBR) encoded streams.

When the codec finishes compressing a quality-based VBR stream, it records the bit rate and buffer window of the resulting content. When you read a file containing a stream encoded with quality-based VBR, the profile obtained from the reader will note the bit rate and buffer window as well as the maximum bit rate and maximum buffer window. This configuration in the profile normally signifies a bit-rate constrained variable bit rate stream. As a result, when you set the profile on the writer, it will expect a preprocessing pass for the stream, because bit-rate constrained VBR streams require two-pass encoding. You should treat the stream as if it were a bit-rate constrained VBR stream and deliver the samples for preprocessing. Because you are using the values returned after encoding the content at a particular quality level, those values represent the desired quality level. Of course, the quality of the re-encoded output will be somewhat degraded anyway, as a result of the re-encoding.

## Related topics

<dl> <dt>

[**Copying Data from One File to Another**](copying-data-from-one-file-to-another.md)
</dt> <dt>

[**Copying Streams Without Decompressing the Data**](copying-streams-without-decompressing-the-data.md)
</dt> </dl>

 

 




