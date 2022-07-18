Welcome to filter.

To use this software, go ahead to your terminal in mac/linux and go to the directory where this file is in your computer.

Then use the following code to compile the code and create a fresh executable of the code:

user filter %  make filter

Next, create a folder in the same directory to keep the output files
Next, run the executable.

Usage:
./filter <option: -r,-g,-s,-b> <input_file_full_location> <output_file_full_location>

About the options:
-r : Lets you apply the lateral inversion effect
-g : Lets you apply the grayscale effect
-s : Lets you apply the sepia effect
-b : Lets you apply the blurring effect (uses box blurring technique)

Example:

When I open my mac's terminal, I see this:

munshifahimuzzaman@Munshis-MacBook-Air % 

Step 1: I go into the directory where my code lives using the cd command.

munshifahimuzzaman@Munshis-MacBook-Air % cd desktop/filter

munshifahimuzzaman@Munshis-MacBook-Air filter %

Step 2: Once I am there I create a new folder/directory to store the output files.

munshifahimuzzaman@Munshis-MacBook-Air filter % mkdir output_files

Step 3: Compile the file and create an executable:

munshifahimuzzaman@Munshis-MacBook-Air % make filter

Step 4: Use the code to apply the desired files from the desired images (stored in the 'images' directory)

munshifahimuzzaman@Munshis-MacBook-Air % ./filter images/tower.bmp output_files/tower_inverted.bmp

(Use whatever version of the names of 'images' and 'output_files' directories are in your case. Make sure the locations you're feeding in the above command actually exist)