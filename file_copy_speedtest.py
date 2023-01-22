import time
import os
import shutil
from datetime import datetime

start_time = time.time()
duration = 3600 # 30 minutes in seconds
source_folder = 'Folder with files to copy'
destination_folder = './Speedtest_Cache'
total_speed = 0
file_count = 0

while time.time() - start_time < duration:
    try:
        for file in os.listdir(source_folder):
            source_file = os.path.join(source_folder, file)
            destination_file = os.path.join(destination_folder, file)
            file_size = os.path.getsize(source_file)
            start_copy = time.time()
            print(f'Started copying {file} at {datetime.now().strftime("%Y-%m-%d %H:%M:%S")}')
            shutil.copy2(source_file, destination_file)
            end_copy = time.time()
            copy_time = end_copy - start_copy
            speed = (file_size / copy_time) * 8
            total_speed += speed
            file_count += 1
            print(f'{file} copied at {speed / (1024 * 1024):.2f} Mbps')
            print("Aborted by user. Deleting copied files...")
            for file in os.listdir(destination_folder):
                os.remove(os.path.join(destination_folder, file))
            print("Files deleted.")
            remaining_time = int((start_time + duration) - time.time())
            print(f'Remaining time: {remaining_time} seconds')
    except Exception as e:
        print(f'Error: {e}')
        print('Waiting for the server connection...')
        time.sleep(5)  # wait for 5 seconds before trying again

average_speed = total_speed / file_count
print(f'Avg. speed: {average_speed / (1024 * 1024):.2f} Mbps')
print(f"Loop ran for {duration} minutes.")
