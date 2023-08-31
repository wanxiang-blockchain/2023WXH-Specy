

import { createStore, createLogger } from 'vuex'
import common from './common/common'
const debug = process.env.NODE_ENV !== 'production'
export default createStore({
    modules: {
        common
    },
    strict: debug,
    plugins: debug ? [createLogger()] : []
})