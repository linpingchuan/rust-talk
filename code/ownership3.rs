fn main() {
    let vec = Vec::new();
    vec.push(1);
    vec.push(2);

    let elem = &vec[0];
    take(vec); // err: cannot move out of borrowed content
}

fn take(vec: Vec) {
    // when this function returns, vec is deallocated
}
