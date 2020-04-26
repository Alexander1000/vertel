#ifndef VERTEL_GRAPHIC_INCLUDE
#define VERTEL_GRAPHIC_INCLUDE

namespace Vertel
{
    class Graphic
    {
    public:
        Graphic(int argc, char* argv[]);
        void start();
    protected:
        static void display();
        static void reshape(int w, int h);
        static void specialKeys( int key, int x, int y );
        static void keyboard (unsigned char key, int x, int y);
    };
}

#endif
