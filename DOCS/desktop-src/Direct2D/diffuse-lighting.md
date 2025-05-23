---
title: Spot-diffuse lighting effect
description: Use the spot-diffuse lighting effect to create an image that appears to be a non-reflective surface with where the light source is limited to a directed cone of light and the light is scattered in all directions.
ms.assetid: 9048D664-28DB-4DB6-9B95-3A61A1EDF5EC
keywords:
- spot diffuse lighting effect
ms.topic: concept-article
ms.date: 05/31/2018
---

# Spot-diffuse lighting effect

Use the spot-diffuse lighting effect to create an image that appears to be a non-reflective surface with where the light source is limited to a directed cone of light and the light is scattered in all directions. This effect uses the alpha channel as a height map and lights the image with a spot light source.

The color of the output bitmap is a result of light color, light position, and the surface geometry. The alpha channel output for each pixel with diffuse lighting is always 1.0.

The CLSID for this effect is CLSID\_D2D1SpotDiffuse.

-   [Example image](#example-image)
-   [Effect properties](#effect-properties)
-   [Scale modes](#scale-modes)
-   [Requirements](#requirements)
-   [Related topics](#related-topics)

## Example image

The example here shows the input and output images of the spot-diffuse lighting effect.

![effect example screenshot that shows ](images/spot-diffuse-example.png)

The effect calculates the final output pixel values are calculated using these equations:

![output bitmap calculation](images/spot-diffuse-formula.png)

Where:<dl> k<sub>d</sub> = diffuse lighting constant. Specified by the user.  
![normal vector symbol.](images/point-spec-mathchar-n.png) = surface normal unit vector, a function of x and y.  
![light vector symbol.](images/distant-spec-mathchar-l.png) = unit vector pointing from surface to light.  
L<sub>r</sub>, L<sub>g</sub>, L<sub>b</sub> = the light color in RGB components.  
</dl>

## Effect properties



| Display name and index enumeration                                                     | Type and default value                                                                      | Description                                                                                                                                                                                                                                                                                                                                                                                              |
|----------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| LightPosition<br/> D2D1\_SPOTDIFFUSE\_PROP\_LIGHT\_POSITION<br/>           | D2D1\_VECTOR\_3F<br/> {0.0f, 0.0f, 0.0f}<br/>                                   | The light position of the point light source. The property is a D2D1\_VECTOR\_3F defined as (x, y, z). The units are in device-independent pixels (DIPs) and are unbounded.<br/>                                                                                                                                                                                                                   |
| PointsAt<br/> D2D1\_SPOTDIFFUSE\_PROP\_POINTS\_AT<br/>                     | D2D1\_VECTOR\_3F<br/> {0.0f, 0.0f, 0.0f}<br/>                                   | Where the spot light is focused. The property is exposed as a D2D1\_VECTOR\_3F with   (x, y, z). The units are in DIPs and the values are unbounded.<br/>                                                                                                                                                                                                                                          |
| Focus<br/> D2D1\_SPOTDIFFUSE\_PROP\_FOCUS<br/>                             | FLOAT<br/> 1.0f<br/>                                                            | The focus of the spot light. This property is unitless and is defined between 0 and 200.<br/>                                                                                                                                                                                                                                                                                                      |
| LimitingConeAngle<br/> D2D1\_SPOTDIFFUSE\_PROP\_LIMITING\_CONE\_ANGLE<br/> | FLOAT<br/> 90.0f<br/>                                                           | The cone angle that restricts the region where the light is projected. No light is projected outside the cone. The limiting cone angle is the angle between the spot light axis (the axis between the *LightPosition* and *PointsAt* properties) and the spot light cone. This property is defined in degrees and must be between 0 to 90 degrees.<br/>                                            |
| DiffuseConstant<br/> D2D1\_SPOTDIFFUSE\_PROP\_DIFFUSE\_CONSTANT<br/>       | FLOAT<br/> 1.0f<br/>                                                            | The ratio of diffuse reflection to amount of incoming light. This property must be between 0 and 10,000 and is unitless. <br/>                                                                                                                                                                                                                                                                     |
| SurfaceScale<br/> D2D1\_SPOTDIFFUSE\_PROP\_SURFACE\_SCALE<br/>             | FLOAT<br/> 1.0f<br/>                                                            | The scale factor in the Z direction. The surface scale is unitless and must be between 0 and 10,000.<br/>                                                                                                                                                                                                                                                                                          |
| Color<br/> D2D1\_SPOTDIFFUSE\_PROP\_COLOR<br/>                             | D2D1\_VECTOR\_3F<br/> {1.0f, 1.0f, 1.0f}<br/>                                   | The color of the incoming light. This property is exposed as a Vector 3   (R, G, B) and used to compute L<sub>R</sub>, L<sub>G</sub>, L<sub>B</sub>. <br/>                                                                                                                                                                                                                                         |
| KernelUnitLength<br/> D2D1\_SPOTDIFFUSE\_PROP\_KERNEL\_UNIT\_LENGTH<br/>   | D2D1\_VECTOR\_2F<br/> {1.0f, 1.0f}<br/>                                         | The size of an element in the Sobel kernel used to generate the surface normal in the X and Y direction. This property maps to the dx and dy values in the Sobel gradient. This property is a D2D1\_VECTOR\_2F(Kernel Unit Length X, Kernel Unit Length Y) and is defined in (DIPs/Kernel Unit). The effect uses bilinear interpolation to scale the bitmap to match size of kernel elements.<br/> |
| ScaleMode<br/> D2D1\_SPOTDIFFUSE\_PROP\_SCALE\_MODE<br/>                   | D2D1\_SPOTDIFFUSE\_SCALE\_MODE<br/> D2D1\_SPOTDIFFUSE\_SCALE\_MODE\_LINEAR<br/> | The interpolation mode the effect uses to scale the image to the corresponding kernel unit length. There are six scale modes that range in quality and speed. See [Scale modes](#scale-modes) for more info.<br/>                                                                                                                                                                                  |



 

## Scale modes



| Enumeration                                           | Description                                                                                                                                                                                          |
|-------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| D2D1\_SPOTDIFFUSE\_SCALE\_MODE\_NEAREST\_NEIGHBOR     | Samples the nearest single point and uses that. This mode uses less processing time, but outputs the lowest quality image.                                                                           |
| D2D1\_SPOTDIFFUSE\_SCALE\_MODE\_LINEAR                | Uses a four point sample and linear interpolation. This mode outputs a higher quality image than nearest neighbor.                                                                                   |
| D2D1\_SPOTDIFFUSE\_SCALE\_MODE\_CUBIC                 | Uses a 16 sample cubic kernel for interpolation. This mode uses the most processing time, but outputs a higher quality image.                                                                        |
| D2D1\_SPOTDIFFUSE\_SCALE\_MODE\_MULTI\_SAMPLE\_LINEAR | Uses 4 linear samples within a single pixel for good edge anti-aliasing. This mode is good for scaling down by small amounts on images with few pixels.                                              |
| D2D1\_SPOTDIFFUSE\_SCALE\_MODE\_ANISOTROPIC           | Uses anisotropic filtering to sample a pattern according to the transformed shape of the bitmap.                                                                                                     |
| D2D1\_SPOTDIFFUSE\_SCALE\_MODE\_HIGH\_QUALITY\_CUBIC  | Uses a variable size high quality cubic kernel to perform a pre-downscale the image if downscaling is involved in the transform matrix. Then uses the cubic interpolation mode for the final output. |



 

> [!Note]  
> If you don't select a mode, the effect defaults to D2D1\_SPOTDIFFUSE\_SCALE\_MODE\_LINEAR.

 

## Requirements



| Requirement | Value |
|--------------------------|------------------------------------------------------------------------------------|
| Minimum supported client | Windows 8 and Platform Update for Windows 7 \[desktop apps \| Windows Store apps\] |
| Minimum supported server | Windows 8 and Platform Update for Windows 7 \[desktop apps \| Windows Store apps\] |
| Header                   | d2d1effects.h                                                                      |
| Library                  | d2d1.lib, dxguid.lib                                                               |



 

## Related topics

<dl> <dt>

[**ID2D1Effect**](/windows/win32/api/d2d1_1/nn-d2d1_1-id2d1effect)
</dt> </dl>

 

