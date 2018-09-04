// Bresenhams Algorithm
// @author : Shivansh Thapliyal
// Date Created : 31/08/2018

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;
// Center point(0,0) = (540,360)

static int mousex[2], mousey[2];
int iii = 0;

void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (iii > 1)
        {
            iii = 0;
        }

        mousex[iii] = x;
        mousey[iii] = y;
        mousey[iii] = 720 - mousey[iii];
        iii = iii + 1;
    }
}
void displayAxis()
{
    glColor3f(1, 1, 1);

    glBegin(GL_LINES);
    glVertex2f(540, 0);
    glVertex2f(540, 680);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0, 360);
    glVertex2f(1080, 360);
    glEnd();
}

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void genLine(int x0, int y0, int x1, int y1)
{
    // either we have {x(k+1),y(k)} or we have {x(k+1),y(k)+1)}

    /*float dy = (float)(abs(y2) - abs(y1));
    float dx = (float)(abs(x2) - abs(x1));
    int p0 = 2 * dy - dx;
    float x = x1, y = y1;
	if (x1< x2)
      {
            x = x1;
            y = y1;
       }
       else
        {
             x = x2;
            y = y2;
             x1 = x1;
            y1 = y1;
        }
    draw_pixel(x, y);
    int p = p0;
    int k;
    if (dx >= dy)
    {
        if (x2 > x)
        {
            if (y2 > y)
            {
                for (k = 0; k < dx; k++)
                {
                    if (p < 0)
                    {
                        x = x + 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy;
                    }

                    else
                    {
                        x = x + 1;
                        y = y + 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy - 2 * dx;
                    }
                }
            }
            if (y1 < y)
            {
                for (k = 0; k < dx; k++)
                {
                    if (p < 0)
                    {
                        x = x + 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy;
                    }

                    else
                    {
                        x = x + 1;
                        y = y - 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy - 2 * dx;
                    }
                }
            }
        }
        if (x1 < x)
        {
            if (y1 > y)
            {
                for (k = 0; k < dx; k++)
                {
                    if (p < 0)
                    {
                        x = x - 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy;
                    }

                    else
                    {
                        x = x - 1;
                        y = y + 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy - 2 * dx;
                    }
                }
            }
            if (y1 < y)
            {
                for (k = 0; k < dx; k++)
                {
                    if (p < 0)
                    {
                        x = x - 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy;
                    }

                    else
                    {
                        x = x - 1;
                        y = y - 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy - 2 * dx;
                    }
                }
            }
        }
    }

    // now for slope > 1
    else if (dy > dx)
    {
        float p = 2 * dx - dy;
        if (x1 > x)
        {
            if (y1 > y)
            {
                for (k = 0; k < dy; k++)
                {
                    if (p < 0)
                    {
                        y = y + 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy;
                    }

                    else
                    {
                        x = x + 1;
                        y = y + 1;
                        glVertex2i(x, y);
                        p = p + 2 * dy + 2 * dx;
                    }
                }
            }


            if (y1 < y)
            {
                for (k = 0; k < dy; k++)
                {
                    if (p < 0)
                    {
                        y = y - 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy;
                    }

                    else
                    {
                        x = x + 1;
                        y = y - 1;
                        glVertex2i(x, y);
                        p = p + 2 * dy + 2 * dx;
                    }
                }
            }
        }
        if (x1 < x)
        {
            if (y1 > y)
            {
                for (k = 0; k < dy; k++)
                {
                    if (p < 0)
                    {
                        y = y + 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy;
                    }

                    else
                    {
                        x = x - 1;
                        y = y + 1;
                        glVertex2i(x, y);
                        p = p + 2 * dy + 2 * dx;
                    }
                }
            }
            if (y1 < y)
            {
                for (k = 0; k < dy; k++)
                {
                    if (p < 0)
                    {
                        y = y - 1;
                        draw_pixel(x, y);
                        p = p + 2 * dy;
                    }

                    else
                    {
                        x = x - 1;
                        y = y - 1;
                        glVertex2i(x, y);
                        p = p + 2 * dy + 2 * dx;
                    }
                }
            }
        }
        glEnd();
        glFlush();*/

	int dx = abs (x1 - x0);
  int dy = abs (y1 - y0);
  int x, y;
  if (dx >= dy)
  {
   int d = 2*dy-dx;
   int ds = 2*dy;
   int dt = 2*(dy-dx);
       if (x0 < x1)
      {
            x = x0;
            y = y0;
       }
       else
        {
             x = x1;
            y = y1;
             x1 = x0;
            y1 = y0;
        }
      draw_pixel(x, y);
   while (x < x1)
  {
        if (d < 0)
        d += ds;
       else {
            if (y < y1) {
              y++;
             d += dt;
             }
            else {
              y--;
           d += dt;
          }
            }
   x++;
       draw_pixel(x, y);
      }
       }
       else {
            int d = 2*dx-dy;
             int ds = 2*dx;
             int dt = 2*(dx-dy);
            if (y0 < y1) {
           x = x0;
           y = y0;
             }
             else {
           x = x1;
             y = y1;
             y1 = y0;
             x1 = x0;
            }
            draw_pixel(x, y);
       while (y < y1)
        {
             if (d < 0)
                 d += ds;
             else {
                     if (x > x1){
                     x--;
                      d += dt;
                   } else {
                     x++;
                     d += dt;
                   }
              }
              y++;
              draw_pixel(x, y);
       }
       }


}
void displayLine(int mousex[], int mousey[])
{
    int x1, y1, x2, y2;

    x1 = mousex[0];
    y1 = mousey[0];
    x2 = mousex[1];
    y2 = mousey[1];

    // written some code for color difference

    if (x1 > 540 && x2 > 540 && y1 < 360 && y2 < 360)
    {
        // inside first quadrant
        glColor3f(1, 0, 0);
    }

    else if (x1 < 540 && x2 < 540 && y1 < 360 && y2 < 360)
    {
        // inside second quadrant
        glColor3f(0, 1, 0);
    }

    else if (x1 < 540 && x2 < 540 && y1 > 360 && y2 > 360)
    {
        // inside third quadrant
        glColor3f(0, 0, 1);
    }

    else if (x1 > 540 && x2 > 540 && y1 > 360 && y2 > 360)
    {
        // inside fourth quadrant
        glColor3f(0, 1, 1);
    }

    else
    {
        // line passing through two quadrants
        glColor3f(1, 1, 1);
    }

    /*glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
      glEnd();
    */

    // calling line genration function
    genLine(x1, y1, x2, y2);
    glutPostRedisplay();
}

void name(int x, int y, char String[], int a, int b, int c)
{
    glColor3f(a,b,c);
    glRasterPos2i(x,y);
    int l=strlen(String);
    for (int i=0; i<l; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
    }
}

void draw(void)
{
    static bool flag = false;

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1080.0, 0.0, 720.0);
    glColor3f(1, 1, 1);

    displayAxis();

   	char string1[64]="Shivansh Thapliyal";
	char string2[64]="Souradeep Banerjee";
	char string3[64]="Shishir Goyal";
	char string4[64]="Siddharth Sharma";

	name(0.0f,25.0f,string1,1,0,0);
	name(0.0f,50.0f,string2,0,1,0);
	name(0.0f,75.0f,string3,255,165,0);
	name(0.0f,100.0f,string4,0,0,1);
	char string7[64]="Assignment 1 - Computer Graphics";
	name(450.0f,700.0f,string7,1,1,1);
    if (iii >= 2)
    {
        displayLine(mousex, mousey);
    }
    glutPostRedisplay();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(300, 500);
    glutInitWindowSize(1080, 720);
    glutCreateWindow("Assignment 1 - Computer Graphics");
    glutMouseFunc(mouseClick);
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
