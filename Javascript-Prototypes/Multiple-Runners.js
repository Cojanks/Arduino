var led = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; //16

// Multiple Runners
var numRunners = 2; // # of runners/tails
var distBetweenRunners = 4; // distance between the end of one runner and the start of another

function loop(repeat) {
    for (var repeater = 1; repeater <= repeat; repeater++) {

        // Main program call
        runMultipleRunners(numRunners, distBetweenRunners);

    }
}

// Run multiple Runners through a strip.
// Takes two arguments: runnersNum: # of runners,  distBetweenRunners (OPTIONAL): distance between ends of runners. Defaults to 0/no distance
function runMultipleRunners(runnersNum, distBetweenRunners) {
    resetArray();
    if (typeof distBetweenRunners === undefined) {
        distBetweenRunners = 0;
    }
    var blockLength = led.length / runnersNum; //18/2 = 9

    if (led.length % blockLength === 0) {
        for (var p = blockLength; p > 0; p--) {

            var blockPositionCounter = p;

            var outputVal; // JS demo variable only

            if (p < distBetweenRunners && distBetweenRunners > 0) {
                outputVal = 0; //'off' state pixel color/brightness here
            } else {
                outputVal = p - distBetweenRunners; // Brightest/Main Pixel value here
            }

            for (var i = 0; i < led.length; i++) { // 0
                if (blockPositionCounter >= blockLength) {
                    led[i] = outputVal;
                    blockPositionCounter = 1;
                    distBetweenRunners > 0 ? outputVal = 0 : outputVal = 1; // JS demo variables only
                } else if (blockPositionCounter < distBetweenRunners && distBetweenRunners > 0) {
                    led[i] = outputVal;
                    outputVal = 0; // JS demo variable only
                    blockPositionCounter++;
                } else {
                    led[i] = outputVal;
                    outputVal++; // JS demo variable only
                    blockPositionCounter++;
                }
            }

            console.log(led);
            resetArray();
        }
    } else {
        console.log("Error: Strip length is not compatible with set number of Runners");
    }
}

function resetArray() {
    for (let t = 0; t < led.length; t++) {
        led[t] = 0;
    }
}

loop(2);