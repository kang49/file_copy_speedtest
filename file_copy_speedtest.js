const fs = require('fs');
const path = require('path');

const startTime = new Date().getTime();
const duration = 30 * 60 * 1000; // 30 minutes in milliseconds
const sourceFolder = 'Folder with files to copy';
const destinationFolder = './Speedtest_Cache';
let totalSpeed = 0;
let fileCount = 0;

while (new Date().getTime() - startTime < duration) {
    try {
        fs.readdirSync(sourceFolder).forEach(file => {
            const sourceFile = path.join(sourceFolder, file);
            const destinationFile = path.join(destinationFolder, file);
            const fileSize = fs.statSync(sourceFile).size;
            const startCopy = new Date().getTime();
            console.log(`Started copying ${file} at ${new Date().toISOString()}`);
            fs.copyFileSync(sourceFile, destinationFile);
            const endCopy = new Date().getTime();
            const copyTime = endCopy - startCopy;
            const speed = (fileSize / copyTime) * 8;
            totalSpeed += speed;
            fileCount++;
            console.log(`${file} copied at ${speed / (1024 * 1024)} Mbps`);
            console.log("Aborted by user. Deleting copied files...");
            fs.readdirSync(destinationFolder).forEach(file => {
                fs.unlinkSync(path.join(destinationFolder, file));
            });
            console.log("Files deleted.");
            const remainingTime = (startTime + duration) - new Date().getTime();
            console.log(`Remaining time: ${remainingTime} milliseconds`);
        });
    } catch (error) {
        console.log(`Error: ${error}`);
        console.log('Waiting for the server connection...');
        setTimeout(() => {}, 5000); // wait for 5 seconds before trying again
    }
}

const averageSpeed = totalSpeed / fileCount;
console.log(`Avg. speed: ${averageSpeed / (1024 * 1024)} Mbps`);
console.log(`Loop ran for ${duration / (60 * 1000)} minutes.`);