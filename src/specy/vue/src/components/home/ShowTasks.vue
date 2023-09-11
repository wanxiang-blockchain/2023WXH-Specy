<template>
  <div class="container">
    <h2 class="text-left mt-5 mb-6 pl-2 font-weight-bold font-main-color">
      {{ title }}
    </h2>
    <div v-if="!showTabel" class="border-1 box-empty">
      <h2>Please connect the wallet and create a task!</h2>
    </div>
    <div v-if="showTabel" class="table-responsive">
      <table class="table table-hover">
        <thead class="bg-light">
          <tr>
            <th class="font-second-color">Name</th>
            <th class="font-second-color">Host Chain</th>
            <th class="font-second-color">Msg Type</th>
            <th class="font-second-color">Status</th>
          </tr>
        </thead>

        <tbody>
          <tr
            v-for="(row, index) in currentPageData"
            :key="index"
            class="tr-border"
          >
            <td @click="detail(row)">{{ row.name }}</td>
            <td>{{ row.connectionId }}</td>
            <td>{{ row.msg }}</td>
            <td class="status">Active</td>
          </tr>
        </tbody>
      </table>
    </div>
    <nav
      v-if="showTabel"
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
import { ref, computed, onMounted, watch } from "vue";
import { useStore } from "vuex";
import { useRouter } from "vue-router";
import { useAddress } from "@/def-composables/useAddress";
import { userTasks } from "../../def-composables/userTasks";
import { env } from "../../env";
import axios from "axios";
const props = defineProps({
  title: {
    type: String,
    required: true,
  },
  itemsPerPage: {
    type: Number,
    default: 5, // You can adjust the default value
  },
});
let store = useStore();
const { address } = useAddress();
watch(
  () => store.state.common.address,
  (newVal, oldVal) => {
    const url =
      env.apiURL + `/specy-network/specy/specy/task_all_by_owner/${newVal}`;
    axios
      .get(url)
      .then((response) => {
        tableData.value = response.data.tasks;
      })
      .catch((error) => {
        console.error("Error fetching data:", error);
      });
  }
);
let showTabel = computed(() => {
  if (useAddress.value == "") {
    return false;
  }
  if (
    tableData.value.length == 0 ||
    tableData.value == null ||
    tableData.value.length == 0
  ) {
    return false;
  }

  return true;
});

const router = useRouter();
let tableData = ref([]);
let currentPage = ref(1);
const handledTableData = ref([]);
let totalPages = computed(() => {
  return Math.ceil(tableData.value.length / props.itemsPerPage);
});
let currentPageData = computed(() => {
  if (tableData.value.length != 0) {
    const startIndex = (currentPage.value - 1) * props.itemsPerPage;
    const endIndex = startIndex + props.itemsPerPage;
    for (let i = 0; i < tableData.value.length; i++) {
      let json = JSON.parse(tableData.value[i].msg);
      handledTableData.value[i] = Object.assign({}, tableData.value[i]);
      handledTableData.value[i].msg = json["@type"];
    }
    return handledTableData.value.slice(startIndex, endIndex);
  }
});
const goToPage = (page) => {
  if (page >= 1 && page <= totalPages.value) {
    currentPage.value = page;
  }
};
const detail = (task) => {
  store.dispatch("task/setTask", task);
  router.push("/detail");
};
const getUserTasks = () => {
  if (store.state.common.address != "") {
    let { tasks, isLoading } = userTasks(100);
    const timer = setInterval(() => {
      if (isLoading.value == false) {
        tableData.value = tasks.value;
        clearInterval(timer); // 停止定时器
      } else {
        console.log("wait");
      }
    }, 1000);
  }
};
onMounted(() => {
  if (store.state.common.address.length != "") {
    getUserTasks(store);
  }
});
</script>
  
  <style scoped lang="scss">
$main-color: rgb(45, 114, 179);
.font-main-color {
  color: #212121;
}
.font-second-color {
  color: #757575;
}
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

.table th {
  border: none; /* Remove top border from table headers */
  border: 1px gray;
}
.status {
  color: rgb(45, 114, 179);
  font-weight: 600;
}
.box-empty {
  border: 1px solid #f5f5f5;
  height: 300px;
  border-radius: 5px;
  display: flex; /* 使用 flex 布局 */
  justify-content: center; /* 在水平方向上居中对齐 */
  align-items: center; /* 在垂直方向上居中对齐 */
  color: rgba($color: #000000, $alpha: 0.3);
}
table {
  border-collapse: separate;
  border-spacing: 0 25px; /* 10px 是你想要的行间距 */
}
</style>
  