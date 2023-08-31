// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements ecall_test_check_rule method.

#include "RuleEnclave.h"

using namespace std;


// std::mutex mtx_requestHandler;

// test check rule parameters
uint32_t request_id = 0;

// TODO fix segment fault
string erc20_rule = "regulation erc20\n"
                    "\n"
                    "entities {\n"
                    "\tentity Account {\n"
                    "\t\tAddress\n"
                    "\t\tBalance is number\n"
                    "\t}\n"
                    "\n"
                    "\tentity Approve {\n"
                    "\t\tAgent\n"
                    "\t\tClient\n"
                    "\t}\n"
                    "\n"
                    "\tentity Transfer {\n"
                    "\t\tOriginator\n"
                    "\t\tSender\n"
                    "\t\tReceiver\n"
                    "\t\tValue is number\n"
                    "\t}\n"
                    "\n"
                    "\tentity SuspiciousAccountList is set[Account]\n"
                    "\tentity VerifiedAccountList is set[Account]\n"
                    "}\n"
                    "\n"
                    "rules {\n"
                    "\trule transfer_account_investigation {\n"
                    "\t\tTransfer.Sender not in SuspiciousAccountList\n"
                    "\n"
                    "\t\tTransfer.Receiver not in SuspiciousAccountList\n"
                    "\t}\n"
                    "\n"
                    "\trule single_transfer_limit {\n"
                    "\t\t0 < Transfer.Value <= 20,000\n"
                    "\t}\n"
                    "\n"
                    "\trule period_transfer_limit {\n"
                    "\t\tcount on Transfer provided Transfer.Sender and Transfer.Receiver within 7 days <= 10\n"
                    "\n"
                    "\t\taccumulate Transfer.Value on Transfer provided Transfer.Sender within 1 day <= 20,000\n"
                    "\t}\n"
                    "}";

string hello_world_rule = "regulation hello_world\n"
                          "\n"
                          "entities {\n"
                          "    entity Hello {\n"
                          "        World\n"
                          "    }\n"
                          "}\n"
                          "\n"
                          "rules {\n"
                          "    rule r1 {\n"
                          "        Hello.World >= 0\n"
                          "        Hello.World >= 0\n"
                          // "        Hello.World >= 100 >= 0\n"
                          "    }\n"
                          "}";

string number_attribute_rule = "regulation number_attribute\n"
                               "\n"
                               "entities {\n"
                               "    entity Number {\n"
                               "        Attribute is number\n"
                               "    }\n"
                               "}\n"
                               "\n"
                               "rules {\n"
                               "    rule r1 {\n"
                               "        Number.Attribute >= 100\n"
                               "    }\n"
                               "}";

string set_not_in_rule = "regulation set_not_in\n"
                         "\n"
                         "entities {\n"
                         "    entity Element {\n"
                         "        Attribute\n"
                         "    }\n"
                         "\n"
                         "    entity Set is set\n"
                         "}\n"
                         "\n"
                         "rules {\n"
                         "    rule r1 {\n"
                         "        Element.Attribute not in Set\n"
                         //  "        Element.Attribute in Set\n"
                         "    }\n"
                         "}";

// TODO fix segment fault
string count_on_rule = "regulation count_on\n"
                       "\n"
                       "entities {\n"
                       "    entity Count {\n"
                       "        Attribute is number\n"
                       "    }\n"
                       "}\n"
                       "\n"
                       "rules {\n"
                       "    rule r1 {\n"
                       //    "        count on Count where true within 1 days >= 10\n"
                       "        count on Count provided Count.Attribute within 1 day >= 10\n"
                       "    }\n"
                       "}";

// TODO fix segment fault
string date_time_format_rule = "regulation date_time_format\n"
                               "\n"
                               "entities {\n"
                               "    entity Date {\n"
                               "        Attribute\n"
                               "    }\n"
                               "\n"
                               "    entity Time {\n"
                               "        Attribute\n"
                               "    }\n"
                               "}\n"
                               "\n"
                               "rules {\n"
                               "    rule r1 {\n"
                               "        true after 2021-01-01\n"
                               "        Date.Attribute >= 100 before 2021-01-01\n"
                               "    }\n"
                               "\n"
                               "    rule r2 {\n"
                               "        false within 100 days\n"
                               "        Time.Attribute < 20,000 within 200 days\n"
                               "    }\n"
                               "}";

// TODO fix segment fault
string if_statement_rule = "regulation if_statement\n"
                           "\n"
                           "entities {\n"
                           "    entity If {\n"
                           "        Attribute is boolean\n"
                           "    }\n"
                           "    entity Number {\n"
                           "        Attribute is number\n"
                           "    }\n"
                           "}\n"
                           "\n"
                           "rules {\n"
                           "    rule r1 {\n"
                           "        if If.Attribute then {\n"
                           "            Number.Attribute > 100\n"
                           "        } else {\n"
                           "            Number.Attribute > 200\n"
                           "        }\n"
                           "    }\n"
                           "}";

// TODO fix segment fault (fixed after changing to newer version Grammar)
string order_of_precedence_rule = "regulation order_of_precedence\n"
                                  "\n"
                                  "entities {\n"
                                  "    entity Order {\n"
                                  "        Attribute is number\n"
                                  "    }\n"
                                  "}\n"
                                  "\n"
                                  "rules {\n"
                                  "    rule r1 {\n"
                                  "        Order.Attribute < 100 + 10 * 20\n"
                                  "    }\n"
                                  "}";

// vector<string> rule_id_list = {"r1"};
vector<string> rule_id_list = {"transfer_account_investigation"};

void ecall_test_check_rule(void)
{
    ocall_print_string("enter ecall_test_check_rule", __FILE__, __LINE__);

    // RuleEnclaveStatus status_code;
    // vector<bool> status_list;

    // // STATUS: OK (after changing to simpler rule grammar)
    // ocall_print_string("test erc20 rule", __FILE__, __LINE__);
    // // request_handler.CheckRule(to_string(request_id++), erc20_rule, rule_id_list);
    // RequestHandler request_handler;
    // status_code = request_handler.CheckRule("erc20", erc20_rule, rule_id_list, &status_list);
    // if (status_code != RuleEnclaveStatus::kOK)
    // {
    //     ocall_print_string("CheckRule failed for erc20", __FILE__, __LINE__);
    // }

    // // STATUS: OK
    // ocall_print_string("test hello world rule");
    // request_handler.CheckRule(to_string(request_id++), hello_world_rule, rule_id_list);

    // // STATUS: OK
    // ocall_print_string("test number attribute rule");
    // request_handler.CheckRule(to_string(request_id++), number_attribute_rule, rule_id_list);

    // // STATUS: OK
    // ocall_print_string("test set not in rule");
    // request_handler.CheckRule(to_string(request_id++), set_not_in_rule, rule_id_list);

    // // STATUS: OK (after changing to simpler rule grammar)
    // ocall_print_string("test count on rule");
    // request_handler.CheckRule(to_string(request_id++), count_on_rule, rule_id_list);

    // // STATUS: OK (after changing to simpler rule grammar)
    // ocall_print_string("test date time format rule");
    // request_handler.CheckRule(to_string(request_id++), date_time_format_rule, rule_id_list);

    // // STATUS: OK (after changing to simpler rule grammar)
    // ocall_print_string("test if statement rule");
    // request_handler.CheckRule(to_string(request_id++), if_statement_rule, rule_id_list);

    // // STATUS: OK (after changing to simpler rule grammar)
    // ocall_print_string("test order of precedence rule");
    // request_handler.CheckRule(to_string(request_id++), order_of_precedence_rule, rule_id_list);

    ocall_print_string("exit ecall_test_check_rule", __FILE__, __LINE__);
}