#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // Iterate over each row of pixels
    for (int i = 0; i < height; i++)
    {
        // Iterate over each cloumn of pixels
        for (int j = 0; j < width; j++)
        {
            // Check if pixel is black
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00)
            {
                // Change color of pixel
                image[i][j].rgbtBlue = 0xaa;
            }
        }
    }
}
