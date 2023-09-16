## Task Information

* Contract Address
```
osmo1suhgf5svhu4usrurvxzlgn54ksxmn8gljarjtxqnapv8kjnp4nrsll0sqv
```

* Execute Method
```
{"follow": {"new_follows": [""]}}
```

* RuleFile

```
task autoFollow entities friend { entity follower {  address is string     follows is list[ string ] }} input { usera is string userb is string} output { new_follows is list[string] } rules { rule checkNewFollowers {  followsA = select follower.follows where follower.address == inputdata.usera  followsB = select follower.follows where follower.address == inputdata.userb  newFollows = collect followsB where followsB not in followsA   outputdata.new_follows = newFollows }}execute { check rule checkNewFollowers})
```


* Check Data
```
{"inputdatas": {"usera": "osmo1pgcee0wjzj5rayax64qh04ptqkrx7lpthccyaw242j37ppfxd2zqchrasn", "userb": "osmo12smx2wdlyttvyzvzg54y2vnqwq2qjateuf7thj"}}
```