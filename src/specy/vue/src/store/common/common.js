

// initial state
// shape: [{ id, quantity }]
const state = () => ({
    address: ''
})

// getters
const getters = {
    getUserAddress: (state, getters) => {
        return state.address;
    }

}

// actions
const actions = {
    setUserAddress({ commit, state }, value) {
        commit('setUserAddress', value)
    }
}

// mutations
const mutations = {

    setUserAddress(state, value) {
        state.address = value
    }
}

export default {
    namespaced: true,
    state,
    getters,
    actions,
    mutations
}