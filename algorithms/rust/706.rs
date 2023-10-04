struct MyHashMap {
    table: Vec<Vec<(i32, i32)>>,
    size: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
#[allow(dead_code)]
impl MyHashMap {
    fn new() -> Self {
        let size = 2381;
        Self {
            table: vec![vec![]; size],
            size,
        }
    }

    fn put(&mut self, key: i32, value: i32) {
        let hash_key = self.hash(key);
        for (k, v) in self.table[hash_key].iter_mut() {
            if *k == key {
                *v = value;
                return;
            }
        }
        self.table[hash_key].push((key, value));
    }

    fn get(&self, key: i32) -> i32 {
        let hash_key = self.hash(key);
        for (k, v) in self.table[hash_key].iter() {
            if *k == key {
                return *v;
            }
        }
        -1
    }

    fn remove(&mut self, key: i32) {
        let hash_key = self.hash(key);
        for (idx, kv) in self.table[hash_key].iter().enumerate() {
            if kv.0 == key {
                self.table[hash_key].remove(idx);
                return;
            }
        }
    }

    fn hash(&self, key: i32) -> usize {
        ((key as usize) * 2 + 97) % self.size
    }
}

fn main() {
    println!("Hello, world!");
}
