import { cosmos, log } from "@graphprotocol/graph-ts";
import { Follow } from "../generated/schema";

/*
处理follow函数event
*/
export function handleWasmEvent(data: cosmos.EventData): void {
  const contract_address = data.event.getAttributeValue("_contract_address");
  if (contract_address == 'osmo1qckrd6hpqg7ldvv9wehdt2npgmguluhs67erhc3dcwm8uxtpjgnq3z039h') {
    const method = data.event.getAttributeValue("method");

    if (method == 'follow') {

      const sender = data.event.getAttributeValue("sender");
      const address = data.event.getAttributeValue("address");
      let follow = Follow.load(sender);
      if (follow == null) {
        log.info("user dont exsit,create it:{}", [sender]);
        follow = new Follow(sender);
        follow.address = sender;
        let follows: string[] = [];
        if (address != null) {
          follows.push(address);
          follow.follows = follows;
        }

      } else {
        log.info("user already exsit:{}", [sender]);
        if (follow.follows != null) {
          if (address != null) {
            follow.follows!.push(address);
          }
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
      let follow = Follow.load(sender);
      if (follow == null) {
        log.info("user dont exsit:{}", [sender]);
        follow = new Follow(sender);
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
