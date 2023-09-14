<template>
  <header class="flex p-5">
    <!-- <IgntLogo class="mx-2.5" /> -->
    <img src="/specylogo.png" alt="logo" class="logo-image ml-5" />

    <nav class="flex flex-1 justify-between">
      <!-- <h1>Friends Demo</h1> -->
      <ul class="flex items-center">
        <li
          class="text-3 px-4 font-normal"
          v-for="item in navItems"
          :key="item.label"
        >
          <IgntLink :item="item"></IgntLink>
        </li>
      </ul>
      <div><IgntAcc /></div>
    </nav>
  </header>
</template>
<script setup lang="ts">
import { ref, type PropType } from "vue";
import { IgntLink } from "@ignt/vue-library";
import IgntAcc from "@/components/IgntAcc.vue";

type MenuItem = {
  label: string;
  to?: string;
  href?: string;
};
const props = defineProps({
  navItems: {
    type: Array as PropType<Array<MenuItem>>,
    required: true,
  },
});
const navItems = ref(props.navItems);
</script>
<style>
.logo-image {
  width: 290px;
  height: 70px;
}
</style>