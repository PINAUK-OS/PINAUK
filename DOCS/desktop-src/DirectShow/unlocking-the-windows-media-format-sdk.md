---
description: Unlocking the Windows Media Format SDK
ms.assetid: 7ede8bda-3b26-452d-8ce9-cd2410ffd9f4
title: Unlocking the Windows Media Format SDK
ms.topic: concept-article
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Unlocking the Windows Media Format SDK

\[The feature associated with this page, [DirectShow](/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

To access version 7 or 7.1 of the Windows Media Format SDK, an application must provide a software certificate, also called a key, at run time. This key is contained in a static library called wmstub.lib to which the application links at build time. An individualized key is only required for creating or reading DRM-protected files. Non-DRM files can be created using the static library provided with the Windows Media Format SDK. For details on obtaining the DRM key, see the Windows Media Format SDK. A DirectShow application provides its certificate to the WM ASF Writer when it is added to the filter graph. The application must register as a key provider using the COM **IServiceProvider** and **IObjectWithSite** interfaces. Using this technique, the application implements a key provider class derived from **IServiceProvider**. This class implements the three standard COM methods—**AddRef**, **QueryInterface**, and **Release**—along with one additional method, **QueryService**, which is called by the filter graph manager. **QueryService** calls the Windows Media Format SDK method [**WMCreateCertificate**](/previous-versions/windows/desktop/legacy/dd757745(v=vs.85)) and returns to the filter graph manager a pointer to the certificate that was created. If the certificate is valid, the filter graph manager allows the graph-building process to proceed.

> [!Note]  
> To build an application, include Wmsdkidl.h for the prototype for [**WMCreateCertificate**](/previous-versions/windows/desktop/legacy/dd757745(v=vs.85)), and link to the Wmstub.lib library.

 

The following code example illustrates the basic steps in this process:


```C++
// Declare and implement a key provider class derived from IServiceProvider.

class CKeyProvider : public IServiceProvider {
public:
    // IUnknown interface
    STDMETHODIMP QueryInterface(REFIID riid, void ** ppv);
    STDMETHODIMP_(ULONG) AddRef();
    STDMETHODIMP_(ULONG) Release();

    CKeyProvider();

    // IServiceProvider
    STDMETHODIMP QueryService(REFIID siid, REFIID riid, void **ppv);
    
private:
    ULONG m_cRef;
};

CKeyProvider::CKeyProvider() : m_cRef(0)
{
}

// IUnknown methods
ULONG CKeyProvider::AddRef()
{
    return InterlockedIncrement(&m_cRef);
}

ULONG CKeyProvider::Release()
{
    ASSERT(m_cRef > 0);

    ULONG lCount = InterlockedDecrement(&m_cRef);
    if (m_cRef == 0) 
    {
        delete this;
        return (ULONG)0;
    }
    return (ULONG)lCount;
}

// We only support IUnknown and IServiceProvider.
HRESULT CKeyProvider::QueryInterface(REFIID riid, void ** ppv)
{
    if (!ppv) return E_POINTER;

    if (riid == IID_IUnknown) 
    {
        *ppv = (void *) static_cast<IUnknown *>(this);
        AddRef();
        return S_OK;
    }
    if (riid == IID_IServiceProvider) 
    {
        *ppv = (void *) static_cast<IServiceProvider *>(this);
        AddRef();
        return S_OK;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP CKeyProvider::QueryService(REFIID siid, REFIID riid, void **ppv)
{
    if (!ppv) return E_POINTER;

    if (siid == __uuidof(IWMReader) && riid == IID_IUnknown) 
    {
        IUnknown *punkCert;
        HRESULT hr = WMCreateCertificate(&punkCert);
        if (SUCCEEDED(hr)) 
        {
            *ppv = (void *) punkCert;
        }
        return hr;
    }
    return E_NOINTERFACE;
}

////////////////////////////////////////////////////////////////////
//
// These examples illustrate the sequence of method calls
// in your application. Error checking is omitted for brevity.
//
///////////////////////////////////////////////////////////////////

// Create the filter graph manager, but don't add any filters.
IGraphBuilder *pGraph;
hr = CreateFilterGraph(&pGraph);

...

// Instantiate the key provider class, and AddRef it
// so that COM doesn't try to free our static object.

CKeyProvider prov;
prov.AddRef();  // Don't let COM try to free our static object.

// Give the graph an IObjectWithSite pointer for callbacks and QueryService.
IObjectWithSite* pObjectWithSite = NULL;

hr = pGraph->QueryInterface(IID_IObjectWithSite, (void**)&pObjectWithSite);
if (SUCCEEDED(hr))
{
    // Use the IObjectWithSite pointer to specify our key provider object.
    // The filter graph manager will use this pointer to call
    // QueryService to do the unlocking.
    // If the unlocking succeeds, then we can build our graph.

    pObjectWithSite->SetSite((IUnknown *) (IServiceProvider *) &prov);
    pObjectWithSite->Release();
}

// Now build the graph.
```



## Related topics

<dl> <dt>

[Creating ASF Files in DirectShow](creating-asf-files-in-directshow.md)
</dt> </dl>

 

 
