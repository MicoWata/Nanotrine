#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <gl/gl.h>

// GL TYPES

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
typedef float GLfloat;
typedef double GLdouble;
typedef char GLchar;
typedef long long GLsizeiptr;

// GL FUNCTION TYPES AND ADRESSES

// CHOOSE PIXEL FORMAT
typedef BOOL (WINAPI *PFNWGLCHOOSEPIXELFORMATARBPROC) 
(HDC hdc, int *piAttribIList, FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = NULL;
// CREATE CONTEXT ATTRIBUTES
typedef HGLRC (WINAPI *PFNWGLCREATECONTEXTATTRIBSARBPROC) 
(HDC hDC, HGLRC hShareContext, int *attribList);
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
// CREATE SHADER
typedef GLuint (WINAPI *PFNGLCREATESHADERPROC)
(GLenum);
PFNGLCREATESHADERPROC glCreateShader = NULL;
// SHADER SOURCE
typedef void (WINAPI *PFNGLSHADERSOURCEPROC)
(GLuint, GLsizei, const GLchar**, GLint*);
PFNGLSHADERSOURCEPROC glShaderSource = NULL;
// COMPILE SHADER
typedef void (WINAPI *PFNGLCOMPILESHADERPROC)
(GLuint);
PFNGLCOMPILESHADERPROC glCompileShader = NULL;
// GET SHADER IV
typedef void (WINAPI *PFNGLGETSHADERIVPROC)
(GLuint, GLenum, GLint*);
PFNGLGETSHADERIVPROC glGetShaderiv = NULL;
// GET SHADER INFO LOG
typedef void (WINAPI *PFNGLGETSHADERINFOLOGPROC)
(GLuint, GLsizei, GLsizei*, GLchar*);
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = NULL;
// CREATE PROGRAM
typedef GLuint (WINAPI *PFNGLCREATEPROGRAMPROC)
();
PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
// ATTACH SHADER
typedef GLuint (WINAPI *PFNGLATTACHSHADERPROC)
(GLuint, GLuint);
PFNGLATTACHSHADERPROC glAttachShader = NULL;
// LINK PROGRAM
typedef void (WINAPI *PFNGLLINKPROGRAMPROC)
(GLuint);
PFNGLLINKPROGRAMPROC glLinkProgram = NULL;
// GET PROGRAM IV
typedef void (WINAPI *PFNGLGETPROGRAMIVPROC)
(GLuint, GLenum, GLint*);
PFNGLGETPROGRAMIVPROC glGetProgramiv = NULL;
// GET PROGRAM INFO LOG
typedef void (WINAPI *PFNGLGETPROGRAMINFOLOGPROC)
(GLuint, GLsizei, GLsizei*, GLchar*);
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
// DELETE SHADER
typedef void (WINAPI *PFNGLDELETESHADERPROC)
(GLuint);
PFNGLDELETESHADERPROC glDeleteShader = NULL;
// GENERATE VERTEX ARRAY
typedef void (WINAPI *PFNGLGENVERTEXARRAYSPROC)
(GLsizei, GLuint*);
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = NULL;
// BIND VERTEX ARRAY
typedef void (WINAPI *PFNGLBINDVERTEXARRAYPROC)
(GLuint);
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = NULL;
// DELETE VERTEX ARRAY
typedef void (WINAPI *PFNGLDELETEVERTEXARRAYSPROC)
(GLsizei, GLuint*);
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = NULL;
// GENERATE BUFFER
typedef void (WINAPI *PFNGLGENBUFFERSPROC)
(GLsizei, GLuint*);
PFNGLGENBUFFERSPROC glGenBuffers= NULL;
// BIND BUFFER
typedef void (WINAPI *PFNGLBINDBUFFERPROC)
(GLenum, GLuint);
PFNGLBINDBUFFERPROC glBindBuffer = NULL;
// DELETE BUFFER
typedef void (WINAPI *PFNGLDELETEBUFFERSPROC)
(GLsizei, GLuint*);
PFNGLDELETEBUFFERSPROC glDeleteBuffers = NULL;
// BUFFER DATA
typedef void (WINAPI *PFNGLBUFFERDATAPROC)
(GLenum, GLsizeiptr, void*, GLenum);
PFNGLBUFFERDATAPROC glBufferData = NULL;
// VERTEX ATTRIBUTE POINTER
typedef void (WINAPI *PFNGLVERTEXATTRIBPOINTERPROC)
(GLuint, GLint, GLenum, GLboolean, GLsizei, void*);
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = NULL;
// ENABLE VERTEX ATTRIBUTE ARRAY
typedef void (WINAPI *PFNGLENABLEVERTEXATTRIBARRAYPROC)
(GLuint);
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = NULL;
// USE PROGRAM
typedef void (WINAPI *PFNGLUSEPROGRAMPROC)
(GLuint);
PFNGLUSEPROGRAMPROC glUseProgram = NULL;

// CONSTANTS

// PIXEL FORMAT
#define WGL_DRAW_TO_WINDOW_ARB            	0x2001
#define WGL_ACCELERATION_ARB                0x2003
#define WGL_SUPPORT_OPENGL_ARB              0x2010
#define WGL_DOUBLE_BUFFER_ARB               0x2011
#define WGL_PIXEL_TYPE_ARB                  0x2013
#define WGL_COLOR_BITS_ARB                  0x2014
#define WGL_DEPTH_BITS_ARB                  0x2022
#define WGL_STENCIL_BITS_ARB                0x2023
#define WGL_FULL_ACCELERATION_ARB           0x2027
#define WGL_TYPE_RGBA_ARB                   0x202B
// GRAPHICS CONTEXT
#define WGL_CONTEXT_MAJOR_VERSION_ARB       0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB       0x2092
#define WGL_CONTEXT_PROFILE_MASK_ARB        0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB    0x00000001
// SHADERS
#define GL_FRAGMENT_SHADER                  0x8B30
#define GL_VERTEX_SHADER                    0x8B31
#define GL_COMPILE_STATUS 									0x8B81
#define GL_LINK_STATUS 											0x8B82
// BUFFERS
#define GL_ARRAY_BUFFER 										0x8892
#define GL_ELEMENT_ARRAY_BUFFER 						0x8893
// DRAW MODES
#define GL_STREAM_DRAW 											0x88E0
#define GL_STATIC_DRAW 											0x88E4
#define GL_DYNAMIC_DRAW 										0x88E8
// VERSION
#define GL_MAJOR_VERSION                    0x821B
#define GL_MINOR_VERSION                    0x821C

// VARIABLES

// MAIN
bool Quit = false;
int mouse_x, mouse_y = 0;
int keyboard_key = 0;
int counter = 0;

// GRAPHICS
GLuint VAO = 0;
GLuint VBO = 0;
GLuint shader_program = 0;

static void
main_fail(char failure[])
{
  Quit = true;
	printf(failure);
}

static LRESULT
window_loop(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message) {
		case WM_CREATE:
		{
			SetTimer(window, 0, 100, NULL);
			return 0;
		}
		case WM_DESTROY:
		{
			Quit = true;
			KillTimer(window, 1); 
			PostQuitMessage(0);
			return 0;
		}
	}

	return DefWindowProcA(window, message, wparam, lparam);;
}

static HWND
window_create(HINSTANCE instance)
{
	WNDCLASSA nice_window_class = {
		.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
		.lpfnWndProc = window_loop,
		.hInstance = instance,
		.hCursor = LoadCursor(0, IDC_ARROW),
		.lpszClassName = "nice_class",
	};
	if (!RegisterClass(&nice_window_class)) main_fail("Failed to register nice window.");

	HWND nice_window = CreateWindowEx(
		0,
		nice_window_class.lpszClassName,
		"Window Title",
		WS_OVERLAPPEDWINDOW,
		10, 10,
		1024, 720,
		0, 0,
		instance,
		0
	);
	if (!nice_window) main_fail("Failed to create nice window.");

	return nice_window;
}

static void
window_load() {
	// LOAD OPENGL FUNCTION POINTERS

  // INIT
  wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
  if (wglChoosePixelFormatARB == NULL) { main_fail("wglChoosePixelFormatARB load procedure failed."); }
  wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
  if (wglCreateContextAttribsARB == NULL) { main_fail("wglCreateContextAttribsARB load procedure failed."); }
	// SHADER
  glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
  if (glCreateShader == NULL) { main_fail("CreateShader load procedure failed."); }
  glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
  if (glShaderSource == NULL) { main_fail("ShaderSource load procedure failed."); }
  glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
  if (glCompileShader == NULL) { main_fail("CompileShader load procedure failed."); }
  glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
  if (glGetShaderiv == NULL) { main_fail("GetShaderiv load procedure failed."); }
  glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
  if (glGetShaderInfoLog == NULL) { main_fail("GetShaderInfoLog load procedure failed."); }
	// PROGRAM
  glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
  if (glCreateProgram == NULL) { main_fail("CreateProgram load procedure failed."); }
  glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
  if (glAttachShader == NULL) { main_fail("AttachShader load procedure failed."); }
  glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
  if (glLinkProgram == NULL) { main_fail("LinkProgram load procedure failed."); }
  glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
  if (glGetProgramiv == NULL) { main_fail("glGetProgramiv load procedure failed."); }
  glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
  if (glGetProgramInfoLog == NULL) { main_fail("glGetProgramInfoLog load procedure failed."); }
  glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
  if (glDeleteShader == NULL) { main_fail("DeleteShader load procedure failed."); }
	glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
  if (glUseProgram == NULL) { main_fail("UseProgram load procedure failed."); }
	// BUFFER
  glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
  if (glGenBuffers == NULL) { main_fail("GenBuffers load procedure failed."); }
  glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
  if (glBindBuffer == NULL) { main_fail("BindBuffer load procedure failed."); }
  glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
  if (glDeleteBuffers == NULL) { main_fail("DeleteBuffers load procedure failed."); }
  glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
  if (glBufferData == NULL) { main_fail("BufferData load procedure failed."); }
	// VERTEX ARRAY
	glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
  if (glGenVertexArrays == NULL) { main_fail("GenVertexArrays load procedure failed."); }
  glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
  if (glBindVertexArray == NULL) { main_fail("BindVertexArray load procedure failed."); }
  glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
  if (glDeleteVertexArrays == NULL) { main_fail("DeleteVertexArrays load procedure failed."); }
	// VERTEX ATTRIBUTES
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
  if (glVertexAttribPointer == NULL) { main_fail("VertexAttribPointer load procedure failed."); }
  glEnableVertexAttribArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
  if (glEnableVertexAttribArray == NULL) { main_fail("EnableVertexAttribArray load procedure failed."); }
}

static void
window_boot()
{
	WNDCLASSA dumb_class = {
		.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
		.lpfnWndProc = DefWindowProcA,
		.hInstance = GetModuleHandle(0),
		.lpszClassName = "DumbClass",
	};
	if (!RegisterClassA(&dumb_class)) { main_fail("Failed to register dumb window class."); }

	HWND dumb_window = CreateWindowExA(
		0,
		dumb_class.lpszClassName,
		"DumbWindow",
		0,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		0, 0,
		dumb_class.hInstance,
		0
	);
	if (!dumb_window) { main_fail("Failed to create dumb window."); }

	HDC dumb_device = GetDC(dumb_window);

	PIXELFORMATDESCRIPTOR dumb_pixel_format = {
		.nSize = sizeof(dumb_pixel_format),
		.nVersion = 1,
		.iPixelType = PFD_TYPE_RGBA,
		.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		.cColorBits = 32,
		.cAlphaBits = 8,
		.iLayerType = PFD_MAIN_PLANE,
		.cDepthBits = 24,
		.cStencilBits = 8,
	};

	int dumb_format = ChoosePixelFormat(dumb_device, &dumb_pixel_format);
	if (!dumb_format) { main_fail("Failed to choose dumb pixel format."); }
	if (!SetPixelFormat(dumb_device, dumb_format, &dumb_pixel_format)) { main_fail("Failed to set dumb pixel format."); }

	HGLRC dumb_context = wglCreateContext(dumb_device);
	if (!dumb_context) { main_fail("Failed to create dumb graphics context."); }
	if (!wglMakeCurrent(dumb_device, dumb_context)) { main_fail("Failed make current dumb context."); }

	window_load();

	wglMakeCurrent(dumb_device, 0);
	wglDeleteContext(dumb_context);
	ReleaseDC(dumb_window, dumb_device);
	DestroyWindow(dumb_window);
}

static void
graphics_load(HDC window_context)
{
	int nice_pixel_format[] = {
		WGL_DRAW_TO_WINDOW_ARB,     GL_TRUE,
		WGL_SUPPORT_OPENGL_ARB,     GL_TRUE,
		WGL_DOUBLE_BUFFER_ARB,      GL_TRUE,
		WGL_ACCELERATION_ARB,       WGL_FULL_ACCELERATION_ARB,
		WGL_PIXEL_TYPE_ARB,         WGL_TYPE_RGBA_ARB,
		WGL_COLOR_BITS_ARB,         32,
		WGL_DEPTH_BITS_ARB,         24,
		WGL_STENCIL_BITS_ARB,       8,
		0
	};
	UINT available_formats;
	int nice_format;

	wglChoosePixelFormatARB(window_context, nice_pixel_format, 0, 1, &nice_format, &available_formats);
	if (!available_formats) main_fail("Failed to choose nice graphics pixel format.");

	PIXELFORMATDESCRIPTOR format_description;
	DescribePixelFormat(window_context, nice_format, sizeof(format_description), &format_description);
	if (!SetPixelFormat(window_context, nice_format, &format_description)) main_fail("Failed to describe nice pixel format.");

	int graphics_attributes[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 3,
		WGL_CONTEXT_PROFILE_MASK_ARB,
		WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0,
	};

	HGLRC graphics_context = wglCreateContextAttribsARB(window_context, 0, graphics_attributes);
	if (!graphics_context) { main_fail("Failed to create graphics context."); }

	if (!wglMakeCurrent(window_context, graphics_context)) main_fail("Failed to make current nice graphics context.");
}

static void
graphics_boot()
{
  int success;
  char infoLog[512];
	
	const GLchar *vertexShaderSource = 
	"#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main() {\n"
	" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}";
	const GLchar *fragmentShaderSource = 
	"#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main() {\n"
	" FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}";

	// VERTEX SHADER
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		main_fail("Failed to compile vertex shader.");
  }

	// FRAGMENT SHADER
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		main_fail("Failed to compile fragment shader.");
	}
	
	// LINK PROGRAM
	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertexShader);
	glAttachShader(shader_program, fragmentShader);
	glLinkProgram(shader_program);
	
	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
		main_fail("Failed to link shader program.");
	}

	// DELETE SHADERS
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// BUFFERS
	float vertices[] =
	{
		-0.5, -0.5, 0.0, // left  
		0.5, -0.5, 0.0, // right 
		0.0,  0.5, 0.0  // top   
	}; 

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0); 

	glBindVertexArray(0);
}

static void
graphics_loop()
{
	glClearColor(0.2, 0.3, 0.3, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader_program);
	glBindVertexArray(VAO); 

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

static void
graphics_print()
{
  GLint major, minor; 
  glGetIntegerv(GL_MAJOR_VERSION, &major); 
  glGetIntegerv(GL_MINOR_VERSION, &minor); 
  printf("Using OpenGL Version: %d.%d\n", major, minor);
	printf("Boot done, start loop!\n");
}

static void
main_boot(HWND window, HDC context)
{
	window_boot();
	
	graphics_load(context);
	graphics_boot();

	ShowWindow(window, SW_SHOW);
	UpdateWindow(window);

	graphics_print();
}

static void
main_loop(HWND window, HDC context)
{
	MSG mail;

	while(!Quit) {
		while (PeekMessageA(&mail, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&mail);
			DispatchMessageA(&mail);

			switch(mail.message) {
				case WM_TIMER:
					graphics_loop();
					counter++;
					SwapBuffers(context);
					break;
				case WM_LBUTTONDOWN:
					mouse_x = mail.pt.x;
					mouse_y = mail.pt.y;
					printf("CLICK %i, %i\n", mouse_x, mouse_y);
					break;
				case WM_KEYDOWN:
					keyboard_key = mail.wParam;
					if (keyboard_key == 27) main_fail("PRESS 27 (QUIT)");
					else printf("PRESS %i\n", keyboard_key);
					break;
			}
		}
	}
}

int WINAPI
WinMain(HINSTANCE instance, HINSTANCE prev, LPSTR cmd_line, int show)
{
	HWND window = window_create(instance);
	HDC context = GetDC(window);

	main_boot(window, context);
	main_loop(window, context);

	return 0;
}