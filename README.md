# Arduino
Assorted Arduino Projects

## Javascript-Prototypes
Prototypes of LED strip logic using Javascript 

## Laugh_8x8LED-Matrix
A laughing animation on a 8x8 LED matrix using Elegoo MEGA2560 R3 with the Arduino IDE

## Palette-Gradient-Testing-Notes
Explaination & personal notes of FastLED's fill_gradient, ColorFromPalette, and other palette functions. 

## Switchable-Face_8x8LED-Matrix
Prototyping a 4-button switchable interface to change between different animated faces (Incorporating the Laugh_8x8LED-Matrix animation). Available faces: Normal - Laugh - Angry - Neutral 

## Wrapping-Fade-JS-Test.js
Tests on how to create a wrapping animation for use in a LED strip

## Wrapping-Fade-JS-Test-FastLED.js
Wrapping brightness fade, optimized for FastLED lib



- **Wrapping-Fade-JS-Test:**
Implementation of a color/brightness fade (Fade which is infront and behind a main pixel) which wraps from one end of a LED strip to another.
O(n^2)
```
Creates a looping array like (one loop):
[ 3, 2, 1, 0, 0, 1, 2 ]
[ 2, 3, 2, 1, 0, 0, 1 ]
[ 1, 2, 3, 2, 1, 0, 0 ]
[ 0, 1, 2, 3, 2, 1, 0 ]
[ 0, 0, 1, 2, 3, 2, 1 ]
[ 1, 0, 0, 1, 2, 3, 2 ]
[ 2, 1, 0, 0, 1, 2, 3 ]
```

- **Single-Runner:**
Creates a single runner along the strip, the length is determined by an argument
```
Creates a looping array like (one loop):
[ 9, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8 ]
[ 8, 9, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7 ]
[ 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6 ]
[ 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5 ]
[ 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4 ]
[ 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3 ]
[ 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 1, 2 ]
[ 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 1 ]
[ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0 ]
[ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0 ]
[ 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0 ]
[ 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0 ]
[ 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0 ]
[ 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0 ]
[ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 ]
[ 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]
```


- **Multiple-Runners:**
Creates a multiple runners along the strip, The number of runners and the spacing between are supplies by arguments
```
Creates a looping array like (one loop):
[ 4, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 1, 2, 3 ]
[ 3, 4, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 1, 2 ]
[ 2, 3, 4, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 1 ]
[ 1, 2, 3, 4, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0 ]
[ 0, 1, 2, 3, 4, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0 ]
[ 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 1, 2, 3, 4, 0, 0 ]
[ 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 1, 2, 3, 4, 0 ]
[ 0, 0, 0, 0, 1, 2, 3, 4, 0, 0, 0, 0, 1, 2, 3, 4 ]
```