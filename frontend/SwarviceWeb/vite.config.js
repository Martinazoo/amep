import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react-swc';

export default defineConfig({
  plugins: [react()],
  server: {
    port: 3000, // El port en el qual Vite estarà escoltant
    proxy: {
      '/api': {
        target: 'http://localhost:8060', // El port del teu backend
        changeOrigin: true,
        secure: false,
        rewrite: (path) => path.replace(/^\/api/, ''), // Reescriu el camí eliminant el prefix /api
      },
    },
  },
});

