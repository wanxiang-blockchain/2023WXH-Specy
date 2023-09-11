### Rule and Binding Languages for RegChain

This repository contains rule and binding language definition files
(both written as .g4 for ANTLR 4). We design the languages to easily
and unambiguously write down both regulatory rules and application
bindings.

#### Rule Language

- [Rule Language Key Design Points](g4/rule/README.md)
- [Example Rule Language Texts](resources/examples/rule)


- [Lexer Definition for Rule Language (.g4)](g4/rule/RuleLexer.g4)
- [Parser Definition for Rule Language (.g4)](g4/rule/RuleParser.g4)

#### Binding Language

- [Example Binding Language Texts](resources/examples/binding)


- [Grammar Definition for Binding Language (.g4)](g4/binding/ReColBinding.g4)