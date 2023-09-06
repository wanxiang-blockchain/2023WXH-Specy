<template>
  <div class="container">
    <h2 class="text-left mt-4 mb-6 pl-2 font-weight-bold">{{ title }}</h2>
    <div class="table-responsive">
      <table class="table table-hover">
        <thead class="bg-light">
          <tr>
            <th>Name</th>
            <th>Host Chain</th>
            <th>Msg Type</th>
            <th>Status</th>
          </tr>
        </thead>
        <tbody>
          <tr v-for="(row, index) in currentPageData" :key="index">
            <td @click="detail(row)">{{ row.name }}</td>
            <td>{{ row.connectionId }}</td>
            <td>{{ row.msg }}</td>
            <td class="status"><i class="fal fa-check-badge"></i></td>
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
</template>
  
  <script setup>
import { ref, computed } from "vue";
import { useStore } from "vuex";
import { useRouter } from "vue-router";
const props = defineProps({
  title: {
    type: String,
    required: true,
  },
  tableData: {
    type: Array,
    required: true,
  },
  itemsPerPage: {
    type: Number,
    default: 5, // You can adjust the default value
  },
});
let store = useStore();
const router = useRouter();
const currentPage = ref(1);
const handledTableData = ref([]);
let totalPages = computed(() => {
  return Math.ceil(props.tableData.length / props.itemsPerPage);
});
let currentPageData = computed(() => {
  if (props.tableData.length != 0) {
    const startIndex = (currentPage.value - 1) * props.itemsPerPage;
    const endIndex = startIndex + props.itemsPerPage;
    for (let i = 0; i < props.tableData.length; i++) {
      let json = JSON.parse(props.tableData[i].msg);
      handledTableData.value[i] = Object.assign({}, props.tableData[i]);
      handledTableData.value[i].msg = json["@type"];
    }
    return handledTableData.value.slice(startIndex, endIndex);
  }
});
const goToPage = (page) => {
  if (page >= 1 && page <= totalPages) {
    currentPage = page;
  }
};
const detail = (task) => {
  store.dispatch("task/setTask", task);
  router.push("/detail");
};
</script>
  
  <style scoped lang="scss">
.project-card {
  padding: 20px;
}

.project-title {
  font-size: 24px;
  margin-bottom: 5px;
}

.project-description {
  font-size: 18px;
  margin-top: 5px;
}

.table th,
.table td {
  vertical-align: middle; /* Center content vertically in table cells */
}

.table th {
  border: none; /* Remove top border from table headers */
  border: 1px gray;
}

.table tbody tr {
  margin-bottom: 10px; /* Add margin between table rows */
}

.table {
  border-collapse: separate; /* Separate borders between table cells */
  border-spacing: 0 8px; /* Set spacing between table rows */
}

.pagination {
  margin-top: 20px; /* Add space between table and pagination */
}
</style>
  