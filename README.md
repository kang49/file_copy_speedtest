<h1>File Copy Speed Test</h1>

<p>This project is a simple script that measures the file copy speed from a source folder to a destination folder. It calculates the average speed (in Mbps) of the copy process and the duration of the loop. It also logs the time at which each file is copied and any errors that occur during the process.</p>

<h2>Requirements</h2>
<ul>
  <li>Python 3.x (for the Python version)</li>
  <li>C++ compiler that supports C++17 or later (for the C++ version)</li>
  <li>Node.js and npm (for the JavaScript version)</li>
</ul>

<h2>Installation</h2>
<h3>For the Python version:</h3>
<ul>
  <li>Make sure you have Python 3.x installed on your system. You can check the version by running <code>python --version</code> in your command prompt or terminal.</li>
  <li>Install the following modules: <code>time</code>, <code>os</code>, <code>shutil</code> and <code>datetime</code>.</li>
</ul>

<h3>For the C++ version:</h3>
<ul>
  <li>Make sure you have a C++ compiler that supports C++17 or later. You can check the version by running <code>g++ --version</code> in your command prompt or terminal.</li>
  <li>No additional modules need to be installed.</li>
</ul>

<h3>For the JavaScript version:</h3>
<ul>
  <li>Make sure you have Node.js and npm installed on your system. You can check the version by running <code>node -v</code> and <code>npm -v</code> in your command prompt or terminal.</li>
  <li>Install the following modules: <code>fs</code> and <code>path</code> by running <code>npm install fs path</code></li>
</ul>

<h2>Usage</h2>
<ol>
  <li>Replace the <code>source_folder</code> and <code>destination_folder</code> variables with the appropriate paths on your system.</li>
  <li>Run the script in your command prompt or terminal.</li>
  <li>The script will copy all files from the source folder to the destination folder, and will log the start and end times of each copy, as well as the file copy speed (in Mbps).</li>
  <li>At the end of the loop, the script will calculate the average file copy speed (in Mbps) and the duration of the loop (in minutes).</li>
</ol>

<h2>Notes</h2>
<ul>
  <li>Make sure you have read and write permissions for the source and destination folders.</li>
  <li>The script uses synchronous file system operations, which may cause performance issues or user-interface freezing in real-world applications.
  <li>The C++ version of the script uses the <code>&lt;experimental/filesystem&gt;</code> library, which may not be supported on all systems and is non-portable.</li>
  <li>On JavaScript version, the <code>fs.copyFileSync()</code> method will throw an exception if the destination file already exists. You may want to change the method to <code>fs.copyFile()</code> in order to handle the error by providing a callback function.</li>
</ul>
