import glob

# Collect all .c and .cpp files in the code/pages directory
source_files = glob.glob("*.c") + glob.glob("*.cpp")

# Remove the "code/pages/" prefix and print each file name
for file in source_files:
    print(file)