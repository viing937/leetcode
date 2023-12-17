use std::{
    cmp,
    collections::{BinaryHeap, HashMap},
};

struct FoodRatings {
    food_type: HashMap<String, String>,
    food_rating: HashMap<String, i32>,
    type_pq: HashMap<String, BinaryHeap<(i32, cmp::Reverse<String>)>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FoodRatings {
    #[allow(dead_code)]
    fn new(foods: Vec<String>, cuisines: Vec<String>, ratings: Vec<i32>) -> Self {
        let mut food_type = HashMap::new();
        let mut food_rating = HashMap::new();
        let mut type_pq = HashMap::new();
        for (name, type_, rating) in foods
            .iter()
            .zip(cuisines.iter())
            .zip(ratings.iter())
            .map(|((x, y), z)| (x, y, z))
        {
            food_type.insert(name.clone(), type_.clone());
            food_rating.insert(name.clone(), *rating);
            type_pq
                .entry(type_.clone())
                .or_insert(BinaryHeap::new())
                .push((*rating, cmp::Reverse(name.clone())));
        }
        Self {
            food_type,
            food_rating,
            type_pq,
        }
    }

    #[allow(dead_code)]
    fn change_rating(&mut self, food: String, new_rating: i32) {
        *self.food_rating.get_mut(&food).unwrap() = new_rating;
        self.type_pq
            .entry(self.food_type[&food].clone())
            .or_default()
            .push((new_rating, cmp::Reverse(food.clone())));
    }

    #[allow(dead_code)]
    fn highest_rated(&mut self, cuisine: String) -> String {
        let type_pq = self.type_pq.get_mut(&cuisine).unwrap();
        while let Some((rating, cmp::Reverse(food))) = type_pq.peek() {
            if *rating != self.food_rating[food] {
                type_pq.pop();
                continue;
            }
            return food.clone();
        }
        "".to_owned()
    }
}

fn main() {
    println!("Hello, world!");
}
