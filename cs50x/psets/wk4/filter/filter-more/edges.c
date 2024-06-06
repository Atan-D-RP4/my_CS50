void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
                int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
                int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

                int Gx_Red   = 0, Gy_Red   = 0;
                int Gx_Green = 0, Gy_Green = 0;
                int Gx_Blue  = 0, Gy_Blue  = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        Gx_Red   += copy[k][l].rgbtRed   * Gx[k - i + 1][l - j + 1];
                        Gx_Green += copy[k][l].rgbtGreen * Gx[k - i + 1][l - j + 1];
                        Gx_Blue  += copy[k][l].rgbtBlue  * Gx[k - i + 1][l - j + 1];

                        Gy_Red   += copy[k][l].rgbtRed   * Gy[k - i + 1][l - j + 1];
                        Gy_Green += copy[k][l].rgbtGreen * Gy[k - i + 1][l - j + 1];
                        Gy_Blue  += copy[k][l].rgbtBlue  * Gy[k - i + 1][l - j + 1];
                    }
                }
            }

            int G2_Red   = (Gx_Red * Gx_Red)     + (Gy_Red * Gy_Red);
            int G2_Green = (Gx_Green * Gx_Green) + (Gy_Green * Gy_Green);
            int G2_Blue  = (Gx_Blue * Gx_Blue)   + (Gy_Blue * Gy_Blue);

            image[i][j].rgbtRed     = cap(round(sqrt((float)G2_Red)));
            image[i][j].rgbtGreen   = cap(round(sqrt((float)G2_Green)));
            image[i][j].rgbtBlue    = cap(round(sqrt((float)G2_Blue)));
         }
    }
    return;
}