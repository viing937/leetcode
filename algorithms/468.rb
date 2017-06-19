# @param {String} ip
# @return {String}
def valid_ip_address(ip)
    return "IPv4" if /^(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$/.match(ip)
    return "IPv6" if /^((\h{1,4}):){7}(\h{1,4})$/.match(ip)
    return "Neither"
end
