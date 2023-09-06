<template>
  <div class="container project-card p-2 mt-6">
    <div class="detail">
      <h2 class="mb-5">Detail</h2>
      <div class="task-container border-1 row">
        <div class="col-md-3 p-5 m-3 bg-light">
          <h4 class="mb-4">Registration</h4>
          <p>Owner address</p>
          <p class="p-color">{{ shortAddress }}</p>
          <hr />
          <p>Name</p>
          <p class="p-color">{{ task.name }}</p>
          <hr />
          <p>Hash</p>
          <p class="p-color">{{ shortHash }}</p>
          <hr />
          <p>Connection ID</p>
          <p class="p-color">{{ task.connectionId }}</p>
        </div>
        <div class="col-md-5 p-5 m-3 bg-light">
          <h4 class="mb-4">Meta Data</h4>
          <p>Msg type</p>
          <p class="p-color">{{ task.msg }}</p>
          <hr />
          <p>Rule file content</p>
          <p class="p-color">{{ task.ruleFiles }}</p>
          <hr />
          <p>Check data</p>
          <p class="p-color">{{ task.checkData }}</p>
        </div>
        <div class="col-md-3 p-5 m-3 bg-light">
          <h4 class="mb-4">Status</h4>
          <p>Task type</p>
          <p class="p-color">{{ taskType }}</p>
          <div class="schedule" v-if="task.taskType == 0">
            <p>Schedule type</p>
            <span class="p-color" v-if="task.scheduleType.intervalType == 0">
              Time
            </span>
            <span v-else class="p-color">Block</span>
            <span class="p-color p-5">{{ task.scheduleType.number }}</span>
          </div>

          <hr />
          <p>Last update time</p>
          <p class="p-color">{{ task.updateTime }}</p>
          <hr />
          <p>Last update height</p>
          <p class="p-color">{{ task.updateBlockHeight }}</p>
        </div>
      </div>
      <hr />
    </div>

    <div class="history">
      <h2 class="mb-5">History</h2>

      <div class="table-responsive">
        <table class="table table-hover">
          <thead class="bg-light">
            <tr>
              <th>Date</th>
              <th>Transaction hash</th>
              <th>Executor</th>
              <th>Amount</th>
            </tr>
          </thead>
          <tbody v-if="recordsTable != null">
            <tr v-for="(row, index) in currentPageData" :key="index">
              <td @click="detail(row)">{{ row.timestamp }}</td>
              <td>{{ row.txhash }}</td>
              <td>{{ row.executor }}</td>
              <td>{{ row.amount }}</td>
            </tr>
          </tbody>
        </table>
      </div>
      <nav
        aria-label="Page navigation"
        class="d-flex justify-content-between align-items-center"
      >
        <div>
          <button
            class="btn btn-outline-dark"
            :disabled="currentPage === 1"
            @click="goToPage(currentPage - 1)"
          >
            Previous
          </button>
        </div>
        <p class="m-0">{{ currentPage }} / {{ totalPages }}</p>
        <div>
          <button
            class="btn btn-outline-dark"
            :disabled="currentPage === totalPages"
            @click="goToPage(currentPage + 1)"
          >
            Next
          </button>
        </div>
      </nav>
    </div>
  </div>
</template>
  
<script setup>
import { useStore } from "vuex";
import { onBeforeMount, computed, ref } from "vue";
import { taskRecords } from "../../def-composables/taskHistory";
let store = useStore();
let task = ref();
let recordsTable = ref();
//function
let shortAddress = computed(() => {
  return (
    task.value.owner.substring(0, 20) +
    "..." +
    task.value.owner.substring(41, 46)
  );
});

let shortHash = computed(() => {
  return (
    task.value.hash.substring(0, 20) + "..." + task.value.hash.substring(60, 64)
  );
});
let taskType = computed(() => {
  if (task.value.taskType == 0) {
    return "Period";
  } else {
    return "Custom";
  }
});

const currentPage = ref(1);
const handledTableData = ref([]);
let totalPages = computed(() => {
  return Math.ceil(handledTableData.value.length / 10);
});
let currentPageData = computed(() => {
  if (recordsTable.length != 0) {
    const startIndex = (currentPage.value - 1) * 10;
    const endIndex = startIndex + 10;

    return recordsTable.value.slice(startIndex, endIndex);
  }
});
const goToPage = (page) => {
  if (page >= 1 && page <= totalPages) {
    currentPage = page;
  }
};

onBeforeMount(() => {
  task.value = store.state.task.task;
  console.log(task.value);
  let records = taskRecords(task.value.owner, task.value.name);
  recordsTable = records;
});
</script>
  
<style scoped lang="scss">
$light-bg: #f8f9fa;
.bg-light {
  background-color: $light-bg;
}
.p-color {
  color: rgb(45, 114, 179);
}
</style>
  