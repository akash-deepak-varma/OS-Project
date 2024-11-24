#include <stdio.h>
#include <stdlib.h>

// Function to copy a file
int copy_file(const char *source, const char *destination) {
    FILE *src_file, *dest_file;
    char buffer[1024];
    size_t bytes;

    // Open the source file for reading
    src_file = fopen(source, "rb");
    if (!src_file) {
        perror("custom_mv: Could not open source file");
        return -1;
    }

    // Open the destination file for writing
    dest_file = fopen(destination, "wb");
    if (!dest_file) {
        perror("custom_mv: Could not open destination file");
        fclose(src_file);
        return -1;
    }

    // Copy the contents from source to destination
    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        if (fwrite(buffer, 1, bytes, dest_file) != bytes) {
            perror("custom_mv: Error writing to destination file");
            fclose(src_file);
            fclose(dest_file);
            return -1;
        }
    }

    if (ferror(src_file)) {
        perror("custom_mv: Error reading from source file");
        fclose(src_file);
        fclose(dest_file);
        return -1;
    }

    // Close both files
    fclose(src_file);
    fclose(dest_file);
    return 0;
}

// Function to delete a file
int delete_file(const char *file) {
    if (remove(file) != 0) {
        perror("custom_mv: Could not delete source file");
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: custom_mv <source> <destination>\n");
        return 1;
    }

    // Ensure the source file exists
    if (access(argv[1], F_OK) != 0) {
        fprintf(stderr, "custom_mv: Source file does not exist\n");
        return 1;
    }

    // Copy the source file to the destination
    if (copy_file(argv[1], argv[2]) != 0) {
        fprintf(stderr, "custom_mv: Failed to copy file\n");
        return 1;
    }

    // Delete the source file
    if (delete_file(argv[1]) != 0) {
        fprintf(stderr, "custom_mv: Failed to delete source file\n");
        return 1;
    }

    return 0;
}
