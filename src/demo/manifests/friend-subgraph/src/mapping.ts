import { cosmos, log } from "@graphprotocol/graph-ts";
import { Follower } from "../generated/schema";

/*
处理follow函数event
*/
export function handleWasmEvent(data: cosmos.EventData): void {
  const contract_address = data.event.getAttributeValue("_contract_address");
  if (contract_address == 'osmo1nc5tatafv6eyq7llkr2gv50ff9e22mnf70qgjlv737ktmt4eswrqvlx82r') {
    const method = data.event.getAttributeValue("method");

    if (method == 'follow') {

      const sender = data.event.getAttributeValue("sender");
      const address = data.event.getAttributeValue("address");

      let follow = Follower.load(sender);
      if (follow == null) {
        log.info("user dont exsit,create it:{}", [sender]);
        follow = new Follower(sender);
        follow.address = sender;
        let follows: string[] = [];
        if (address != null) {
          let followsAddr: string[] = address.split(",");
          for (let index = 0; index < followsAddr.length; index++) {
            const element = followsAddr[index];
            follows.push(element);
          }
          follow.follows = follows;
        }

      } else {
        log.info("user already exsit:{}", [sender]);
        if (follow.follows != null) {
          if (address != null) {
            let follows_old = follow.follows
            let followsAddr: string[] = address.split(",");
            for (let index = 0; index < followsAddr.length; index++) {
              const element = followsAddr[index];
              follows_old!.push(element);
            }
            follow.follows = follows_old;
          }
          log.info("end push length:{}", ["" + follow.follows!.length.toString()]);
        }
      }
      let length = 0;
      if (follow.follows != null) {
        length = follow.follows!.length;
      }
      log.info("user follow complete,follows number:{}", ["" + length.toString()]);
      follow.save();
    } else if (method == "register") {
      const sender = data.event.getAttributeValue("sender");
      let follow = Follower.load(sender);
      if (follow == null) {
        log.info("user dont exsit:{}", [sender]);
        follow = new Follower(sender);
        follow.address = sender;
        let follows: string[] = [];
        if (sender != null) {
          follows.push(sender);
        }

        follow.follows = follows;
        follow.save();
      } else {
        log.info("user already exsit:{}", [sender]);
      }
      let length = 0;
      if (follow.follows != null) {
        length = follow.follows!.length;
      }
      log.info("user register complete,follows number:{}", ["" + length.toString()]);

    }
  }
}
