/*
 * This should be named 'plat.h' and then include any 
 * Windows-specific header files needed, to keep them
 * out of the main code.
 */
/* Copyright holders: Sarah Walker
   see COPYING for more details
*/
#ifndef BOX_WIN_H
# define BOX_WIN_H

# ifndef NO_UNICODE
#  define UNICODE
# endif
# define BITMAP WINDOWS_BITMAP
/* # ifdef _WIN32_WINNT
   #  undef _WIN32_WINNT
   #  define _WIN32_WINNT 0x0501
   # endif */
# include <windows.h>
# undef BITMAP


#define szClassName L"86BoxMainWnd"
#define szSubClassName L"86BoxSubWnd"
#define szStatusBarClassName L"86BoxStatusBar"


#define WM_RESETD3D WM_USER
#define WM_LEAVEFULLSCREEN WM_USER + 1

#define WM_SAVESETTINGS 0x8888			/* 86Box-specific message, used to tell the child dialog to save the currently specified settings. */

#define SB_ICON_WIDTH 24


extern HINSTANCE	hinstance;
extern HWND		ghwnd;
extern HWND		status_hwnd;
extern HWND		hwndStatus;
extern int		status_is_open;
extern int		mousecapture;

extern char		openfilestring[260];
extern WCHAR		wopenfilestring[260];

extern int		pause;

extern HMENU		smenu;
extern HMENU		*sb_menu_handles;


#ifdef __cplusplus
extern "C" {
#endif

extern void	leave_fullscreen(void);

extern void	status_open(HWND hwnd);

extern void	deviceconfig_open(HWND hwnd, struct device_t *device);
extern void	joystickconfig_open(HWND hwnd, int joy_nr, int type);

extern int	getfile(HWND hwnd, char *f, char *fn);
extern int	getsfile(HWND hwnd, char *f, char *fn);

extern void	get_executable_name(WCHAR *s, int size);
extern void	set_window_title(WCHAR *s);

extern void	startblit(void);
extern void	endblit(void);

extern void	win_settings_open(HWND hwnd);
extern void	win_menu_update();

extern void	update_status_bar_panes(HWND hwnds);

extern int	fdd_type_to_icon(int type);

extern void	hard_disk_add_open(HWND hwnd, int is_existing);
extern int	hard_disk_was_added(void);

extern void	get_registry_key_map(void);
extern void	process_raw_input(LPARAM lParam, int infocus);

extern int	find_status_bar_part(int tag);

extern void	cdrom_close(uint8_t id);
extern void	update_tip(int meaning);

#ifdef __cplusplus
}
#endif


#endif	/*BOX_WIN_H*/