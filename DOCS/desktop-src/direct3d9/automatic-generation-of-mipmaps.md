---
description: You can now automatically create a mipmap which is a series of textures, each filtered to a different resolution.
ms.assetid: ae5955f9-e52a-41d7-a199-800e37a3e936
title: Automatic Generation of Mipmaps (Direct3D 9)
ms.topic: reference
ms.date: 05/31/2018
---

# Automatic Generation of Mipmaps (Direct3D 9)

You can now automatically create a mipmap which is a series of textures, each filtered to a different resolution. Mipmaps are commonly used to provide different levels of detail when rendering. Automatically generating mipmaps at texture creation time takes advantage of hardware filtering because the mipmap resides in video memory.

To generate a mipmap automatically, set a new usage [D3DUSAGE\_AUTOGENMIPMAP](d3dusage.md) before calling [**CreateTexture**](/windows/desktop/api). Sublevel generation from this point on is completely transparent to the application. Only the top texture level is accessible to the application; the texture sublevels are not accessible since they will be created only when needed by the driver. In cases where sublevel generation may take a lot of time, use [**GenerateMipSubLevels**](/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dbasetexture9-generatemipsublevels) to hint to the driver that it should generate sublevels at a time appropriate for the application.

## Mipmap Filtering

[**SetAutoGenFilterType**](/windows/desktop/api) controls the filtering quality during automatic generation. Changing the filter type dirties the mipmap sublevels and causes them to be regenerated. Use [**GetAutoGenFilterType**](/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dbasetexture9-getautogenfiltertype) to get the current filter type. The default filter type is D3DTEXF\_LINEAR. If the driver doesn't support a linear filter, the filter type will be set to D3DTEXF\_POINT.

These methods have no effect if the texture is not created with [D3DUSAGE\_AUTOGENMIPMAP](d3dusage.md) And no failure is returned. All filter types supported by the driver for regular texture filtering are supported for autogenerated except D3DTEXF\_NONE. For each resource type, drivers should support all the filter types reported in the corresponding texture, CubeTexture, and volumetexture filter caps.

To check which filter types are supported, check to see which caps are supported by the TextureFilterCaps and/or CubeTextureFilterCaps members of [**D3DCAPS9**](/windows/desktop/api/D3D9Caps/ns-d3d9caps-d3dcaps9).

## Mipmap Support

[D3DUSAGE\_AUTOGENMIPMAP](d3dusage.md) is only a hint, and specifying this during texture creation or when calling [**CheckDeviceFormat**](/windows/win32/api/d3d9/nf-d3d9-idirect3d9-checkdeviceformat) would not cause an error on any of the device driver interface (DDI) types.

Calling [**UpdateTexture**](/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-updatetexture) is illegal when the source is an automatically generated mipmap, but the destination is not. The source can be a non-automatically generated mipmap and the destination can be an automatically generated mipmap. In this case, only the topmost matching level is updated. All other source sublevels are ignored. Similarly, when both the source and destination are automatically generated, only the topmost matching level is updated. The sublevels from the source are ignored and the destination sublevels are regenerated.

To check for support for automatic generation of mipmaps, check to see that [D3DCAPS2\_CANAUTOGENMIPMAP](d3dcaps2.md) is set. If it is, call [**CheckDeviceFormat**](/windows/win32/api/d3d9/nf-d3d9-idirect3d9-checkdeviceformat) with [D3DUSAGE\_AUTOGENMIPMAP](d3dusage.md). If the return value is D3D\_OK, the mipmaps are guaranteed to be autogenerated. If the return value is D3DOK\_NOAUTOGEN, this means that the create call will succeed, but there won't be any mipmaps generated.

## Related topics

<dl> <dt>

[Direct3D Textures](direct3d-textures.md)
</dt> </dl>

 

 
