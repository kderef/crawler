odin := 'odin'
flags := ''

dbg_flags := '-debug -use-separate-modules'
opt_flags := '-o:speed'

src := 'main.odin -file'
bin := 'bin/crawler'

alias b := build_debug
alias r := run
alias opt := build_optimised

build_optimised:
    {{odin}} build {{src}} {{flags}} {{opt_flags}} -out:{{bin}}

build_debug:
    {{odin}} build {{src}} {{flags}} {{dbg_flags}} -out:{{bin}}

run:
    {{bin}}
