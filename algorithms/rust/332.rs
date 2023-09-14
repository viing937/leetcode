use std::collections::HashMap;

impl Solution {
    #[allow(dead_code)]
    pub fn find_itinerary(tickets: Vec<Vec<String>>) -> Vec<String> {
        let mut graph: HashMap<&str, Vec<&str>> = HashMap::new();
        for ticket in tickets.iter() {
            let (src, dst) = (ticket[0].as_str(), ticket[1].as_str());
            graph.entry(src).or_insert(vec![]).push(dst);
        }

        for dst_list in graph.values_mut() {
            dst_list.sort_by(|x, y| y.cmp(x));
        }

        let mut stack: Vec<&str> = vec!["JFK"];
        let mut itinerary = vec![];

        while !stack.is_empty() {
            while let Some(next) = graph.entry(stack.last().unwrap()).or_insert(vec![]).pop() {
                stack.push(next);
            }
            itinerary.push(stack.pop().unwrap().to_string());
        }

        itinerary.reverse();
        itinerary
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
