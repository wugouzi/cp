impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        let num_rows = num_rows as usize;
        // 每行一个String
        let mut rows = vec![String::new(); num_rows];
        // z字形往复的迭代器，01232101232......
        let iter = (0..num_rows).chain((1..num_rows-1).rev()).cycle();
        // 按迭代器给出的下标访问对应行，推入字符
        iter.zip(s.chars()).for_each(|(i, c)| rows[i].push(c));
        // collect连接每行
        rows.into_iter().collect()
    }
    pub fn convert1(s: String, num_rows: i32) -> String {
        if num_rows == 1 {
            return s;
        }
        let chars: Vec<_> = s.chars().collect();
        let mut ans = String::with_capacity(s.len());
        let unit: usize = (2 * num_rows - 2) as usize;
        let len = s.len();
        for row in 0..num_rows {
            let mut i = row as usize;
            let step1 = 2 * (num_rows - 1 - row) as usize;
            let step2 = (unit - step1) as usize;
            let mut flag = false;
            while i < len {
                ans.push(chars[i]);
                if step1 == 0 {
                    i += step2;
                } else if step2 == 0 {
                    i += step1;
                } else {
                    i += if flag { step2 } else { step1 };
                    flag = !flag;
                }
            }
        }
        ans
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use super::*;

    #[test]
    fn test6() {
        assert_eq!(Solution::convert(String::from("PAYPALISHIRING"), 3), String::from("PAHNAPLSIIGYIR"));
        assert_eq!(
            Solution::convert("PAYPALISHIRING".to_string(), 4),
            "PINALSIGYAHRPI"
        );
        assert_eq!(
            Solution::convert("test".to_string(), 1),
            "test"
        );
    }

}
