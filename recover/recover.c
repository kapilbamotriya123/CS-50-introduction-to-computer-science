#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


const int block_size = 512;
int x = 0;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    //open memory card first
    FILE *inptr = fopen(argv[1], "r");
    FILE *img = NULL;


    uint8_t buffer[block_size];
    //repeat until the end of the memorycard
    while (fread(buffer, 1, block_size, inptr) == 512)
    {
        //read 512 bytes into a buffer
        //if this is start of new jpeg

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)

        {
            //if its first jpeg
            if (x == 0)
            {
                x++;
                //make a file named xyz jpeg

                char filename[8]; // Buffer to store the formatted filename
                sprintf(filename, "%03i.jpg", x -1); // Format the filename
                img = fopen(filename, "w");//opens the file we just named to write
                //start writing into it
                fwrite(buffer, 1, block_size, img);
            }
            //if its not a fist jpeg
            else
            {
                x++;
                //close the already opened file
                fclose(img);
                //open a new file
                char filename[8]; // Buffer to store the formatted filename
                sprintf(filename, "%03i.jpg", x - 1); // Format the filename
                img = fopen(filename, "w");
                //start writing into a new one
                fwrite(buffer, 1, block_size, img);
            }
        }

        //if its not a start of a new jpeg
        else
        {
            //if you have been already writing in a jpeg
            if (img != NULL && x > 0)
            {
                //continue writing in that one
                fwrite(buffer, 1, block_size, img);
            }
        }

    }
    if (x!=0)
        fclose(img);
    fclose(inptr);
}
