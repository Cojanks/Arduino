//          0   0   0   0   0   0   0    
//              i                   

// led length: 7
// i = 1
// fadeLength = 2

// Fade
var led = [0,0,0,0,0,0,0]; // Your LED array
var fadeLength = 2; // This is the # of pixels on either side of the main pixel that will be the fade
var mainPixel = 3; // This will be a RGB value but im using a numerical value to demo in the console

function loop(repeat) { // loop(), ignore the repeat arg
    for(var repeater = 1; repeater<=repeat; repeater++){ //This is so I can see the print out in action over several loops, delete when moving over to arduino
        for (let i = 0; i < led.length; i++) { 
            // Reset whole array. This is usually a clear() or hide() function from a LED library
            resetArray();

            // Set main pixel color/brightness, etc (Using a number here so I can see what's happening)
            // This is where you set the brightest/central pixel
            led[i] = mainPixel; // ex: We are at i = 1 so [ 0, mainPixel, 0, 0, 0, 0, 0 ];

            // Once the main pixel is set, you look to the left/right for the fade, starting with the furthest out
            for(var p = fadeLength; p > 0; p--) { 
                // find the furthest left/right array index of your fade
                var left = i - p; 
                var right = i + p; 

                // Handle Left
                //  If the left most part of the fade does not fall outside of the array:
                if(left >= 0) {
                    // Set the value of the LED here, color change, yadda yadda. May need additional variables
                    led[i-p] = mainPixel - p; 
                } 
                // else if the fade needs to wrap from the left to the end of the array:
                else if(left < 0) {
                    // Set the value of the LED here, color change, yadda yadda. May need additional variables
                    led[led.length + left] = mainPixel - p; 
                }

                // Handle Right
                //  If the right most part of the fade does not fall outside of the array:
                if (right < led.length) {
                    // Set the value of the LED here, color change, yadda yadda. May need additional variables
                    led[i + p] = mainPixel - p;
                }
                // else if the fade needs to wrap from the right to the beginning of the array:
                else if (right >= led.length) {
                    // Set the value of the LED here, color change, yadda yadda. May need additional variables
                    led[ right - led.length ] = mainPixel - p;
                }
            }
            console.log(led);
        }

        function resetArray(){
            for (let t = 0; t < led.length; t++) {
                led[t] = 0;
            }
        }
    }
}

loop(4);