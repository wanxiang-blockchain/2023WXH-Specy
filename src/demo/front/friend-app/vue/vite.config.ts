import { fileURLToPath, URL } from "node:url";
import { nodeResolve } from "@rollup/plugin-node-resolve";
import { defineConfig } from "vite";
import vue from "@vitejs/plugin-vue";
// https://vitejs.dev/config/
export default defineConfig({
  plugins: [nodeResolve(), vue()],
  resolve: {
    alias: {
      "@": fileURLToPath(new URL("./src", import.meta.url)),
    },
  },
  optimizeDeps: {
    esbuildOptions: {
      define: {
        global: "globalThis",
      },
    },
  },
  server: {
    host: '0.0.0.0',
    proxy: {
      '/subgraphs': {
        target: 'http://3.145.81.95:8000',
        changeOrigin: true
      }
    }
  }
});
