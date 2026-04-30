import { createTheme } from '@mui/material/styles';

const theme = createTheme({
  palette: {
    mode: 'dark',
    primary: {
      main: '#00d4aa',
      light: '#33ddbb',
      dark: '#00a885',
      contrastText: '#0a0e17',
    },
    secondary: {
      main: '#7c4dff',
      light: '#b388ff',
      dark: '#5c35cc',
    },
    error: {
      main: '#ff4757',
    },
    warning: {
      main: '#ffa502',
    },
    success: {
      main: '#2ed573',
    },
    background: {
      default: '#0a0e17',
      paper: '#111827',
    },
    text: {
      primary: 'rgba(255,255,255,0.95)',
      secondary: 'rgba(255,255,255,0.6)',
    },
    divider: 'rgba(255,255,255,0.08)',
  },
  typography: {
    fontFamily: "'Inter', system-ui, -apple-system, sans-serif",
    button: {
      textTransform: 'none',
      fontWeight: 600,
    },
  },
  shape: {
    borderRadius: 10,
  },
  components: {
    MuiAccordion: {
      styleOverrides: {
        root: {
          background: 'rgba(17, 24, 39, 0.6)',
          backdropFilter: 'blur(12px)',
          border: '1px solid rgba(255,255,255,0.06)',
          borderRadius: '12px !important',
          marginBottom: '4px',
          boxShadow: 'none',
          '&:before': { display: 'none' },
          '&.Mui-expanded': {
            margin: '0 0 4px 0',
            border: '1px solid rgba(0, 212, 170, 0.2)',
          },
          transition: 'border-color 0.3s ease, background 0.3s ease',
        },
      },
    },
    MuiAccordionSummary: {
      styleOverrides: {
        root: {
          background: 'transparent !important',
          borderRadius: '12px',
          minHeight: '56px !important',
          padding: '0 16px',
          '&.Mui-expanded': {
            minHeight: '56px !important',
          },
        },
        content: {
          margin: '6px 0 !important',
          '&.Mui-expanded': {
            margin: '6px 0 !important',
          },
        },
      },
    },
    MuiAccordionDetails: {
      styleOverrides: {
        root: {
          padding: '0 12px 12px',
          background: 'transparent',
        },
      },
    },
    MuiButton: {
      styleOverrides: {
        root: {
          borderRadius: 8,
          fontWeight: 600,
          boxShadow: 'none',
          '&:hover': {
            boxShadow: 'none',
          },
        },
        containedPrimary: {
          background: 'linear-gradient(135deg, #00d4aa 0%, #00b894 100%)',
          color: '#0a0e17',
          '&:hover': {
            background: 'linear-gradient(135deg, #00e6b8 0%, #00d4aa 100%)',
          },
        },
      },
    },
    MuiFab: {
      styleOverrides: {
        root: {
          borderRadius: 12,
          boxShadow: '0 4px 15px rgba(0,0,0,0.3)',
          backdropFilter: 'blur(12px)',
          border: '1px solid rgba(255,255,255,0.1)',
          transition: 'all 0.3s cubic-bezier(0.4, 0, 0.2, 1)',
          '&:hover': {
            transform: 'translateY(-2px)',
            boxShadow: '0 6px 20px rgba(0, 212, 170, 0.3)',
          },
        },
        extended: {
          background: 'linear-gradient(135deg, #00d4aa 0%, #00b894 100%)',
          color: '#0a0e17',
          fontWeight: 700,
        },
      },
    },
    MuiSlider: {
      styleOverrides: {
        root: {
          color: '#00d4aa',
          height: 4,
        },
        thumb: {
          width: 16,
          height: 16,
          '&:hover, &.Mui-focusVisible': {
            boxShadow: '0 0 0 8px rgba(0, 212, 170, 0.16)',
          },
        },
        track: {
          background: 'linear-gradient(90deg, #00d4aa, #00b894)',
          border: 'none',
        },
        rail: {
          opacity: 0.2,
          backgroundColor: 'rgba(255,255,255,0.2)',
        },
      },
    },
    MuiInput: {
      styleOverrides: {
        root: {
          color: 'rgba(255,255,255,0.9)',
          '&:before': {
            borderBottomColor: 'rgba(255,255,255,0.15)',
          },
          '&:hover:not(.Mui-disabled):before': {
            borderBottomColor: '#00d4aa',
          },
        },
      },
    },
    MuiTextField: {
      styleOverrides: {
        root: {
          '& .MuiOutlinedInput-root': {
            '& fieldset': {
              borderColor: 'rgba(255,255,255,0.12)',
            },
            '&:hover fieldset': {
              borderColor: 'rgba(0, 212, 170, 0.4)',
            },
            '&.Mui-focused fieldset': {
              borderColor: '#00d4aa',
            },
          },
          '& .MuiInputLabel-root': {
            color: 'rgba(255,255,255,0.5)',
          },
        },
      },
    },
    MuiSelect: {
      styleOverrides: {
        root: {
          '& .MuiOutlinedInput-notchedOutline': {
            borderColor: 'rgba(255,255,255,0.12)',
          },
          '&:hover .MuiOutlinedInput-notchedOutline': {
            borderColor: 'rgba(0, 212, 170, 0.4)',
          },
        },
      },
    },
    MuiCheckbox: {
      styleOverrides: {
        root: {
          color: 'rgba(255,255,255,0.4)',
          '&.Mui-checked': {
            color: '#00d4aa',
          },
        },
      },
    },
    MuiDialog: {
      styleOverrides: {
        paper: {
          background: '#1a2332',
          backdropFilter: 'blur(20px)',
          border: '1px solid rgba(255,255,255,0.1)',
          borderRadius: 16,
        },
      },
    },
    MuiFormControlLabel: {
      styleOverrides: {
        label: {
          fontSize: '0.9rem',
          color: 'rgba(255,255,255,0.85)',
        },
      },
    },
  },
});

export default theme;
