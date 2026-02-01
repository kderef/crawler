fn main() {
    let profile = std::env::var("PROFILE").unwrap();

    match profile.as_str() {
        "release" => {
            static_vcruntime::metabuild();
        }
        _ => {}
    }
}
