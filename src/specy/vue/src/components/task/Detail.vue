<template>
  <div class="container project-card p-2 mt-6">
    <div class="detail">
      <h2 class="mb-5">Detail</h2>
      <div class="task-container border-1">task info</div>
      <hr />
    </div>

    <div class="history">
      <h2 class="mb-5">History</h2>
      <div class="row">
        <div class="col-md-2 col-12"></div>
        <div class="col-md-8 col-12"></div>
        <div class="col-md-2 text-right"></div>
      </div>
    </div>
  </div>
</template>
  
<script setup>
import { useStore } from "vuex";
import { onBeforeMount, computed, ref } from "vue";
let store = useStore();
let task = ref();

onBeforeMount(() => {
  task.value = store.state.task.task;
  console.log(task.value);
});
</script>
  
<style scoped lang="scss">
.project-card {
  .project-title {
    font-weight: 600;
    font-size: 40px;
  }

  .project-description {
    font-size: 20px;
    margin-bottom: 30px;
  }
}
</style>
  