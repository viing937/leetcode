# @param {String} code
# @return {Boolean}
def is_valid(code)
    return false if code == "t"
    code = code.gsub(/<!\[CDATA\[.*?\]\]>/, "c")
    prev = nil
    while prev != code do
        prev = code
        code = code.gsub(/<([A-Z]{1,9})>[^<]*<\/\1>/, "t")
    end
    return code == "t" ? true : false
end
