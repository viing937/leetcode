impl Solution {
    #[allow(dead_code)]
    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let max_width = max_width as usize;
        let mut rslt = vec![];

        let mut words_of_line = vec![];
        let mut width = 0;

        for word in words.iter() {
            if word.len() + words_of_line.len() + width > max_width {
                let mut line = String::new();

                if words_of_line.len() == 1 {
                    line.push_str(words_of_line[0]);
                    line.push_str(&" ".repeat(max_width - width));
                } else {
                    let sep = words_of_line.len() - 1;
                    let space_each_sep = (max_width - width) / sep;
                    let sep_has_extra_space = (max_width - width) % sep;
                    for (idx, &w) in words_of_line.iter().enumerate() {
                        if idx != 0 {
                            line.push_str(&" ".repeat(space_each_sep));
                            if idx <= sep_has_extra_space {
                                line.push(' ');
                            }
                        }
                        line.push_str(w);
                    }
                }
                words_of_line.clear();
                width = 0;
                rslt.push(line);
            }
            width += word.len();
            words_of_line.push(word);
        }

        let mut line = words_of_line.join(" ");
        line.push_str(&" ".repeat(max_width - line.len()));
        rslt.push(line);

        rslt
    }
}

struct Solution;

fn main() {
    println!("Hello, world!");
}
