// NANOTRINE

// STANDARD C & WINDOWS HEADERS
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <gl/gl.h>

// 0. OPENGL TYPES, FUNCTIONS AND CONSTANTS

// OPENGL TYPES
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

// CHOOSE PIXEL FORMAT
typedef BOOL (*PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC, int*, FLOAT*, UINT, int*, UINT*);
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB = NULL;
// CREATE CONTEXT ATTRIBUTES
typedef HGLRC (*PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC, HGLRC, int*);
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = NULL;
// CREATE SHADER
typedef GLuint (*PFNGLCREATESHADERPROC)(GLenum);
PFNGLCREATESHADERPROC glCreateShader = NULL;
// SHADER SOURCE
typedef void (*PFNGLSHADERSOURCEPROC)(GLuint, GLsizei, const GLchar**, GLint*);
PFNGLSHADERSOURCEPROC glShaderSource = NULL;
// COMPILE SHADER
typedef void (*PFNGLCOMPILESHADERPROC)(GLuint);
PFNGLCOMPILESHADERPROC glCompileShader = NULL;
// GET SHADER IV
typedef void (*PFNGLGETSHADERIVPROC)(GLuint, GLenum, GLint*);
PFNGLGETSHADERIVPROC glGetShaderiv = NULL;
// GET SHADER INFO LOG
typedef void (*PFNGLGETSHADERINFOLOGPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = NULL;
// CREATE PROGRAM
typedef GLuint (*PFNGLCREATEPROGRAMPROC)();
PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
// ATTACH SHADER
typedef GLuint (*PFNGLATTACHSHADERPROC)(GLuint, GLuint);
PFNGLATTACHSHADERPROC glAttachShader = NULL;
// LINK PROGRAM
typedef void (*PFNGLLINKPROGRAMPROC)(GLuint);
PFNGLLINKPROGRAMPROC glLinkProgram = NULL;
// GET PROGRAM IV
typedef void (*PFNGLGETPROGRAMIVPROC)(GLuint, GLenum, GLint*);
PFNGLGETPROGRAMIVPROC glGetProgramiv = NULL;
// GET PROGRAM INFO LOG
typedef void (*PFNGLGETPROGRAMINFOLOGPROC)(GLuint, GLsizei, GLsizei*, GLchar*);
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
// DELETE SHADER
typedef void (*PFNGLDELETESHADERPROC)(GLuint);
PFNGLDELETESHADERPROC glDeleteShader = NULL;
// GENERATE VERTEX ARRAY
typedef void (*PFNGLGENVERTEXARRAYSPROC)(GLsizei, GLuint*);
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = NULL;
// BIND VERTEX ARRAY
typedef void (*PFNGLBINDVERTEXARRAYPROC)(GLuint);
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = NULL;
// DELETE VERTEX ARRAY
typedef void (*PFNGLDELETEVERTEXARRAYSPROC)(GLsizei, GLuint*);
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = NULL;
// GENERATE BUFFER
typedef void (*PFNGLGENBUFFERSPROC)(GLsizei, GLuint*);
PFNGLGENBUFFERSPROC glGenBuffers= NULL;
// BIND BUFFER
typedef void (*PFNGLBINDBUFFERPROC)(GLenum, GLuint);
PFNGLBINDBUFFERPROC glBindBuffer = NULL;
// DELETE BUFFER
typedef void (*PFNGLDELETEBUFFERSPROC)(GLsizei, GLuint*);
PFNGLDELETEBUFFERSPROC glDeleteBuffers = NULL;
// BUFFER DATA
typedef void (*PFNGLBUFFERDATAPROC)(GLenum, GLsizeiptr, void*, GLenum);
PFNGLBUFFERDATAPROC glBufferData = NULL;
// VERTEX ATTRIBUTE POINTER
typedef void (*PFNGLVERTEXATTRIBPOINTERPROC)(GLuint, GLint, GLenum, GLboolean, GLsizei, void*);
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = NULL;
// ENABLE VERTEX ATTRIBUTE ARRAY
typedef void (*PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint);
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = NULL;
// USE PROGRAM
typedef void (*PFNGLUSEPROGRAMPROC)(GLuint);
PFNGLUSEPROGRAMPROC glUseProgram = NULL;

// PIXEL FORMAT
#define WGL_DRAW_TO_WINDOW_ARB                0x2001
#define WGL_ACCELERATION_ARB                  0x2003
#define WGL_SUPPORT_OPENGL_ARB                0x2010
#define WGL_DOUBLE_BUFFER_ARB                 0x2011
#define WGL_PIXEL_TYPE_ARB                    0x2013
#define WGL_COLOR_BITS_ARB                    0x2014
#define WGL_DEPTH_BITS_ARB                    0x2022
#define WGL_STENCIL_BITS_ARB                  0x2023
#define WGL_FULL_ACCELERATION_ARB             0x2027
#define WGL_TYPE_RGBA_ARB                     0x202B
// CONTEXT ATTRIBUTES
#define WGL_CONTEXT_MAJOR_VERSION_ARB         0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB       	0x2092
#define WGL_CONTEXT_PROFILE_MASK_ARB        	0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB    	0x0001
// SHADERS
#define GL_FRAGMENT_SHADER                  	0x8B30
#define GL_VERTEX_SHADER                    	0x8B31
#define GL_COMPILE_STATUS                     0x8B81
#define GL_LINK_STATUS                        0x8B82
// BUFFERS
#define GL_ARRAY_BUFFER                       0x8892
#define GL_ELEMENT_ARRAY_BUFFER               0x8893
// VERSION
#define GL_MAJOR_VERSION                      0x821B
#define GL_MINOR_VERSION                    	0x821C
// DRAW MODES
#define GL_STREAM_DRAW                        0x88E0
#define GL_STATIC_DRAW                        0x88E4
#define GL_DYNAMIC_DRAW                       0x88E8

// 1. SOME VARIABLES

// MOUSE POSITION
int mouse_x, mouse_y = 0;
// LAST KEY PRESSED
int keyboard_key = 0;
// FRAME COUNT
int frame = 0;
// QUIT
bool Quit = false;
// DEBUG
void main_fail(char failure[])
{
	Quit = true;
	printf(failure);
}

// 2. WINDOW PROCEDURE

LRESULT window_procedure(HWND window, UINT message, WPARAM wparam, LPARAM lparam)
{
	// GET WINDOW MESSAGES
	switch (message) {
		// WHEN WINDOW IS CREATED
		case WM_CREATE:
		{
			// UPDATE FRAME TWICE PER SECOND
			SetTimer(window, 0, 2, NULL);
			return 0;
		}
		// WHEN WINDOW IS CLOSED
		case WM_DESTROY:
		{
			// STOP LOOP
			Quit = true;
			// DESTROY TIMER
			KillTimer(window, 1); 
			// STOP PROCEDURE
			PostQuitMessage(0);
			return 0;
		}
	}
	// PROCESS ANY OTHER MESSAGE
	return DefWindowProcA(window, message, wparam, lparam);;
}

// MAIN
int main() {

	// 3. CREATE WINDOW AND PROGRAM HANDLES

	// GET MODULE HANDLE
	HINSTANCE instance = GetModuleHandle(0);
	// REGISTER NICE WINDOW CLASS
	WNDCLASSA window_class = {
		.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
		.lpfnWndProc = window_procedure,
		.hInstance = instance,
		.hCursor = LoadCursor(0, IDC_ARROW),
		.lpszClassName = "nice_class",
	};
	if (!RegisterClass(&window_class)) main_fail("Failed to register nice window.");
	// CREATE NICE WINDOW
	HWND window = CreateWindowEx(
		0,
		window_class.lpszClassName,
		"Window Title",
		WS_OVERLAPPEDWINDOW,
		10, 10,
		1024, 720,
		0, 0,
		instance,
		0
	);
	if (!window) main_fail("Failed to create nice window.");
	// GET NICE DEVICE CONTEXT
	HDC context = GetDC(window);

	// 4. DUMB PART

	// REGISTER DUMB WINDOW CLASS
	WNDCLASSA dumb_class = {
		.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
		.lpfnWndProc = DefWindowProcA,
		.hInstance = GetModuleHandle(0),
		.lpszClassName = "DumbClass",
	};
	if (!RegisterClassA(&dumb_class)) { main_fail("Failed to register dumb window class."); }
	// CREATE DUMB WINDOW
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
	// GET DUMB DEVICE CONTEXT
	HDC dumb_device = GetDC(dumb_window);
	// DESCRIBE DUMB PIXEL FORMAT
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
	// CHOOSE DUMB PIXEL FORMAT
	int dumb_format = ChoosePixelFormat(dumb_device, &dumb_pixel_format);
	if (!dumb_format) { main_fail("Failed to choose dumb pixel format."); }
	// SET DUMB PIXEL FORMAT
	if (!SetPixelFormat(dumb_device, dumb_format, &dumb_pixel_format)) { main_fail("Failed to set dumb pixel format."); }
	// CREATE DUMB CONTEXT
	HGLRC dumb_context = wglCreateContext(dumb_device);
	if (!dumb_context) { main_fail("Failed to create dumb graphics context."); }
	// MAKE CURRENT DUMB CONTEXT
	if (!wglMakeCurrent(dumb_device, dumb_context)) { main_fail("Failed make current dumb context."); }

	// 5. LOAD OPENGL FUNCTIONS

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
	// DESTROY DUMB STUFF
	wglMakeCurrent(dumb_device, 0);
	wglDeleteContext(dumb_context);
	ReleaseDC(dumb_window, dumb_device);
	DestroyWindow(dumb_window);

	// 6. NICE PART

	// SET NICE GRAPHICS FORMAT
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
	// CHOOSE NICE PIXEL FORMAT
	wglChoosePixelFormatARB(context, nice_pixel_format, 0, 1, &nice_format, &available_formats);
	if (!available_formats) main_fail("Failed to choose nice graphics pixel format.");
	// DESCRIBE NICE PIXEL FORMAT
	PIXELFORMATDESCRIPTOR format_description;
	DescribePixelFormat(context, nice_format, sizeof(format_description), &format_description);
	if (!SetPixelFormat(context, nice_format, &format_description)) main_fail("Failed to describe nice pixel format.");
	// SET GRAPHICS ATTRIBUTES
	int graphics_attributes[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 3,
		WGL_CONTEXT_PROFILE_MASK_ARB,
		WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
		0,
	};
	// CREATE CONTEXT ATTRIBUTES
	HGLRC graphics_context = wglCreateContextAttribsARB(context, 0, graphics_attributes);
	if (!graphics_context) { main_fail("Failed to create graphics context."); }
	// MAKE CURRENT NICE CONTEXT
	if (!wglMakeCurrent(context, graphics_context)) main_fail("Failed to make current nice graphics context.");

	// 7. OPENGL SETUP

	// STORE VERTEX SHADER SOURCES
	const GLchar *vertexShaderSource = 
	"#version 330 core\n"
	"layout (location = 0) in vec3 aPos;\n"
	"void main() {\n"
	" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}";
	// STORE FRAGMENT SHADER SOURCES
	const GLchar *fragmentShaderSource = 
	"#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main() {\n"
	" FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}";
	// STORE VERTEX SHADER COMPILATION STATUS
	int success;
	// STORE VERTEX SHADER INFO LOG
  GLchar infoLog[512];
	// CREATE VERTEX SHADER
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// SET VERTEX SHADER SOURCE
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	// COMPILE VERTEX SHADER
  glCompileShader(vertexShader);
	// GET VERTEX SHADER PARAMETERS
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	// IF COMPILATION FAILED
  if (!success) {
		// WRITE VERTEX SHADER INFO LOG
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		main_fail("Failed to compile vertex shader.");
  }
	// CREATE FRAGMENT SHADER
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// SET FRAGMENT SHADER SOURCE
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	// COMPILE FRAGMENT SHADER
	glCompileShader(fragmentShader);
	// GET FRAGMENT SHADER PARAMETERS
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	// IF COMPILATION FAILED
	if (!success) {
		// WRITE FRAGMENT SHADER INFO LOG
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		main_fail("Failed to compile fragment shader.");
	}
	// CREATE PROGRAM
	GLuint program = glCreateProgram();
	// ATTACH VERTEX SHADER
	glAttachShader(program, vertexShader);
	// ATTACH FRAGMENT SHADER
	glAttachShader(program, fragmentShader);
	// LINK PROGRAM
	glLinkProgram(program);
	// GET PROGRAM PARAMETERS
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	// IF LINKING FAILED
	if (!success) {
		// WRITE PROGRAM INFO LOG
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		main_fail("Failed to link shader program.");
	}
	// DELETE SHADERS
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	// TRIANGLE
	GLfloat vertices[] = {
		-0.5, -0.5, 0.0, // left  
		0.5, -0.5, 0.0, // right 
		0.0,  0.5, 0.0  // top   
	}; 
	// STORE VERTEX ARRAY
	GLuint VAO = 0;
	// STORE VERTEX BUFFER
	GLuint VBO = 0;
	// GENERATE VERTEX ARRAY
	glGenVertexArrays(1, &VAO);
	// GENERATE VERTEX BUFFER
	glGenBuffers(1, &VBO);
	// BIND VERTEX ARRAY
	glBindVertexArray(VAO);
	// BIND VERTEX BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// STORE BUFFER DATA
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// SET VERTEX ATTRIBUTES
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	// ENABLE VERTEX ATTRIBUTES
	glEnableVertexAttribArray(0);
	// UNBIND VERTEX ARRAY 
	glBindVertexArray(0);
	// UNBIND VERTEX BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	// PRINT OPENGL VERSION
	GLint major, minor; 
  glGetIntegerv(GL_MAJOR_VERSION, &major); 
  glGetIntegerv(GL_MINOR_VERSION, &minor); 
  printf("Using OpenGL Version: %d.%d\n", major, minor);
	// OPEN WINDOW
	ShowWindow(window, SW_SHOW);

	// 8. WINDOW LOOP

	// STORE WINDOW MESSAGE
	MSG mail;
	// WHILE QUIT VARIABLE IS FALSE
	while(!Quit) {
		// SET WINDOW MESSAGE
		while (PeekMessageA(&mail, window, 0, 0, PM_REMOVE)) {
			// TRANSLATE MESSAGE
			TranslateMessage(&mail);
			// DISPATCH MESSAGE
			DispatchMessageA(&mail);
			// READ WINDOW MESSAGE
			switch(mail.message) {
				// UPDATE FRAME
				case WM_TIMER:
					// BACKGROUND COLOR
					glClearColor(0.2, 0.3, 0.3, 1.0);
					// CLEAR COLOR & DEPTH BUFFERS
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
					// USE SHADER PROGRAM
					glUseProgram(program);
					// BIND VERTEX ARRAY
					glBindVertexArray(VAO); 
					// DRAW TRIANGLE
					glDrawArrays(GL_TRIANGLES, 0, 3);
					// END FRAME
					SwapBuffers(context);
					// UPDATE FRAME COUNT
					frame++;
					break;
				// LEFT MOUSE BUTTON CLICKED
				case WM_LBUTTONDOWN:
					// SET MOUSE POSITION
					mouse_x = mail.pt.x;
					mouse_y = mail.pt.y;
					// PRINT MOUSE POSITION
					printf("CLICK %i, %i\n", mouse_x, mouse_y);
					break;
				// KEYBOARD KEY PRESSED
				case WM_KEYDOWN:
					// SET KEY NUMBER
					keyboard_key = mail.wParam;
					// IF KEY IS ESC, CLOSE WINDOW 
					if (keyboard_key == 27) main_fail("PRESS 27 (QUIT)");
					// ELSE PRINT KEY NUMBER
					else printf("PRESS %i\n", keyboard_key);
					break;
			}
		}
	}

	return 0;
}
