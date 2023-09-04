# friend demo subgraph



## Deploy


```shell
$ yarn codegen && yarn build
$ yarn create-local && yarn deploy-local

```

For the list of supported networks, see the scripts in the [`package.json`](package.json) file.

## Querying the subgraph

### Query follows
```
query{
  follows{
    id
    address
    follows
  }
}
```
The query result

```
{
  "data": {
    "follows": [
      {
        "id": "0x36c94b4355d27e8656ec587c73bcfb691484e3378f61d1098eb87af8609bbb79",
        "address": "osmo1zaavvzxez0elundtn32qnk9lkm8kmcszydc6a7",
        "follows":["osmo1zaavvzxez0elundtn32qnk9lkm8kmcszydc6a7"]
      },
    ]
  }
}
```

query by address hash

```
query{
  follows(where:{address:"osmo1zaavvzxez0elundtn32qnk9lkm8kmcszydc6a7"}){
    id
  }
}
```
the query result
```
{
  "data": {
    "follows": [
      {
        "id": "osmo1zaavvzxez0elundtn32qnk9lkm8kmcszydc6a7",
      }
    ]
  }
}
```

query one  by id

Notice：use follow not follows
```
query{
  follow(id:"osmo1zaavvzxez0elundtn32qnk9lkm8kmcszydc6a7"){
    id
  }
}
```
