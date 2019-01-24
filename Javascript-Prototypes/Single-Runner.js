var led = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; //16

// Single Runner
var runnerLength = 9;
var mainPixelVal = runnerLength;

function loop(repeat) {
    for (var repeater = 1; repeater <= repeat; repeater++) {

        // Main program call
        runSingleRunner(runnerLength);

    }
}

// Runs a single runner through the strip
// Takes one argument: runnerLengthNum - The length of the Runner
function runSingleRunner(runnerLengthNum) {
    for (let i = 0; i < led.length; i++) {
        resetArray();

        led[i] = mainPixelVal;

        for (var p = runnerLengthNum - 1; p >= 0; p--) {
            var left = i - p;

            if (left >= 0) {
                led[i - p] = mainPixelVal - p;
            } else if (left < 0) {
                led[led.length + left] = mainPixelVal - p;
            }
        }
        console.log(led);
    }
}

function resetArray() {
    for (let t = 0; t < led.length; t++) {
        led[t] = 0;
    }
}

loop(2);