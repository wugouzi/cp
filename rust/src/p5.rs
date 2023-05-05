impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let mut ans:&str = &s[..1];
        // let bytes = s.as_bytes();
        let bytes: Vec<_> = s.chars().collect();
        let n = bytes.len();
        for i in 0..(n-1) {
            let mut j = 1;
            while i + j < n && i >= j && bytes[i-j] == bytes[i+j] {
                j += 1;
            }
            j -= 1;
            if 1+2*j > ans.len() {
                ans = &s[i-j..i+j+1];
            }
            if i + 1 < n && bytes[i] == bytes[i+1] {
                let mut j = 1;
                while i + j + 1 < n && i >= j && bytes[i-j] == bytes[i+j+1] {
                    j += 1;
                }
                j -= 1;
                if 2 + 2 * j > ans.len() {
                    ans = &s[i-j..i+j+2];
                }
            }
        }
        ans.to_string()
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    extern crate test;
    use super::*;

    #[test]
    fn test5() {
        assert_eq!(Solution::longest_palindrome(String::from("babd")), String::from("bab"));
        assert_eq!(Solution::longest_palindrome(String::from("cbbd")), String::from("bb"));
    }

}
