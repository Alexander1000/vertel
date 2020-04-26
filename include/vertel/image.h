#ifndef VERTEL_IMAGE_H
#define VERTEL_IMAGE_H

namespace Vertel
{
    // class for save & load image
    class Image
    {
    public:
        // ширина и высота
        int width;
        int height;

        // глубина цвета
        int depth;

        // битовая карта изображения
        int *bitMap;

        // original file
        char* fileName;

        Image();

        Image(const char* fileName);

        int loadJpeg(const char* fileName);

        int loadJpeg(char* fileName);

        int saveJpeg(const char* fileName);

        int saveJpeg(char* fileName);

        int saveJpegBitmap(const char* fileName, int* bitMap, int width, int height);

        int saveJpegBitmap(char* fileName, int* bitMap, int width, int height);
    };
}

#endif
