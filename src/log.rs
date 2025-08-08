#[cfg(debug_assertions)]
#[macro_export]
macro_rules! log {
    ($($arg:tt)+) => {{
        eprintln!(
            "[\x1b[92mINFO\x1b[0m ] \x1b[93m{}:{}\x1b[0m — {}",
            file!(),
            line!(),
            format_args!($($arg)+)
        );
    }};
}
#[cfg(not(debug_assertions))]
#[macro_export]
macro_rules! log {
    ($($_:tt)+) => {};
}

#[cfg(debug_assertions)]
#[macro_export]
macro_rules! error {
    ($($arg:tt)+) => {{
        eprintln!(
            "[\x1b[91mERROR\x1b[0m] \x1b[93m{}:{}\x1b[0m — {}",
            file!(),
            line!(),
            format_args!($($arg)+)
        );
    }};
}
#[cfg(not(debug_assertions))]
#[macro_export]
macro_rules! error {
    ($($_:tt)+) => {};
}
