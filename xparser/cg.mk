DEFINES	+= -DSTART_END 
DEFINES	+= -DGRAPHICS


PGPLOT_DIR    = /usr/local/pgplot
INCLUDES = /usr/local/pgplot
X11_DIR	      =/usr/X11R6/lib

LDFLAGS += -L$(PGPLOT_DIR)
LDFLAGS += -L$(X11_DIR)

LIBS	+= -lcpgplot -lpgplot -lpng
LIBS	+= -lX11


